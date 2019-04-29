class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int base = 26;
        while (n != 0) {
            result.push_back((n - 1) % base + 'A');
            n = (n - 1) / base;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};