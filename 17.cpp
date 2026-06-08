class Solution {
private:
    const vector<string> keyMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(const string& digits, int start, string& current, vector<string>& result) {
        if (start == digits.size()) {
            result.push_back(current);
            return;
        }

        const string& letters = keyMap[digits[start] - '0'];
        for (const char& c : letters) {
            current.push_back(c);
            backtrack(digits, start + 1, current, result);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};

