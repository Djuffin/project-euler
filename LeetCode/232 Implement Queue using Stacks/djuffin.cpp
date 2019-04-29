class Queue {
    stack<int> incoming, outgoing;
    
    void move() {
        while (!incoming.empty()) {
            outgoing.push(incoming.top());
            incoming.pop();
        }
    }
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        incoming.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (outgoing.empty()) {
            move();
        }
        outgoing.pop();
    }

    // Get the front element.
    int peek(void) {
        if (outgoing.empty()) {
            move();
        }
        return outgoing.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return incoming.empty() && outgoing.empty();
    }
};