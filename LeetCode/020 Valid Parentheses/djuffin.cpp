class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c : s) {
            switch (c)     {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');                    
                    break;
                case '{':
                    stack.push('}');
                    break;
                default: {
                    if (stack.empty()) {
                        return false;
                    }
                    
                    if (stack.top() != c) {
                        return false;
                    }
                    
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};