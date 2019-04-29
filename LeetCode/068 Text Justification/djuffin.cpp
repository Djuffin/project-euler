class Solution {
    int justifyLine(vector<string> *results, string *words, int words_count, int width) {
        vector<string *> words_to_use;
        int current_len = 0;
        for (int i = 0; i < words_count; i++) {
            int new_len = current_len + words[i].size() + (i == 0 ? 0 : 1);
            if (new_len > width) {
                break;
            } else {
                words_to_use.push_back(&words[i]);
                current_len = new_len;
            }
        }
        
        bool last_line = words_to_use.size() == words_count;
        
        int spaces_to_insert = width - current_len;
        int regular_space_size = 1, extra_spaces = 0;
        if (!last_line && words_to_use.size() > 1) {
            regular_space_size = 1 + spaces_to_insert / (words_to_use.size() - 1);
            extra_spaces = spaces_to_insert % (words_to_use.size() - 1);
        } 
        
        string result;
        for(int i = 0; i < words_to_use.size(); i++) {
            if (i != 0) {
                result.append(regular_space_size, ' ');
                if (i <= extra_spaces) {
                    result.append(1, ' ');
                }
            }
            
            result.append(*words_to_use[i]);
        }
        
        if (words_to_use.size() == 1 || last_line) {
            result.append(width - current_len, ' ');
        }
        results->push_back(result);
        
        return words_to_use.size();
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> results;
         for (int i = 0; i < words.size(); ) {
            i += justifyLine(&results, &words[i], words.size() - i, maxWidth);    
         }
         return results;
    }
};