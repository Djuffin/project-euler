class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        
        int carry = 0;
        for (auto ia = a.begin(), ib = b.begin(); ia != a.end() || ib != b.end();) {
            int value = carry;
            if (ia != a.end()) {
                if (*ia++ == '1') value++;
            }
            if (ib != b.end()) {
                if (*ib++ == '1') value++;
            }
            carry = value / 2;
            value %= 2;
            result.push_back(value == 1 ? '1' : '0');
        }
        if (carry != 0) {
            result.push_back('1');
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};