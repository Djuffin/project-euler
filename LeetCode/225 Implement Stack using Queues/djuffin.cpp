class Stack {
    queue<int> q;
    
    void rotate() {
        for (int i = 0, size = q.size() - 1; i < size; i++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        rotate();
        q.pop();
    }

    // Get the top element.
    int top() {
        rotate();
        int result = q.front();
        q.pop();
        q.push(result);
        return result;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};