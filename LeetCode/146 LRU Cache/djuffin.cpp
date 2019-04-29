class LRUCache{
    struct Entry {
      int key, value;
      Entry *prev, *next;
      Entry(int k, int v) {
          key = k;
          value = v;
      }
    };
    
    unordered_map<int, Entry *> key2value;
    int capacity;
    Entry head;
    
    void remove(Entry *entry) {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }
    
    void insert(Entry *entry) {
        entry->next = head.next;
        entry->prev = &head;
        entry->prev->next = entry;
        entry->next->prev = entry;
    }
    
    void delete_oldest() {
        auto e = head.prev;
        if (e == &head) return;
        key2value.erase(e->key);
        remove(e);
        delete e;
    }
    
public:
    LRUCache(int capacity) : head(0, 0) {
        this->capacity = capacity;
        head.prev = head.next = &head;
        
    }
    
    int get(int key) {
        auto it = key2value.find(key);
        if (it == key2value.end()) {
            return -1;
        }
        Entry *e = it->second;
        remove(e);
        insert(e);
        return e->value;
    }
    
    void set(int key, int value) {
        auto it = key2value.find(key);
        if (it != key2value.end()) {
            auto e = it->second;
            remove(e);
            insert(e);
            e->value = value;
        } else {
            if (capacity == key2value.size()) {
                delete_oldest();
            }
            auto e = new Entry(key, value);
            insert(e);
            key2value[key] = e;
        }
    }
};