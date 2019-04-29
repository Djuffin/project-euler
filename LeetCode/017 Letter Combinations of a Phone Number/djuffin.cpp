class Solution {
    vector<string> result;
    
    void add(vector<char> &combination) {
        result.push_back(string(&*combination.begin(), combination.size()));
    }
    
    void search(vector<char> &combination, const vector<int> &digits, int index) {
        static string mapping[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        if (index == digits.size()) {
            add(combination);
            return;
        }
        
        for (char c : mapping[digits[index]]) {
            combination.push_back(c);
            search(combination, digits, index + 1);
            combination.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string strDigits) {
        if (strDigits.size()  == 0) {
            return result;
        }
        vector<int> digits;
        for (auto a : strDigits) {
            digits.push_back(a - '0');
        }
        vector<char> combination;
        search(combination, digits, 0);
        return result;
        
    }
};