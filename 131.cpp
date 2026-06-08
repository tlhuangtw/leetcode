class Solution {
private:
    void backtrack(const string& s, int start, vector<string>& currentPath, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(currentPath);
            return;
        }

        int n = s.size();
        for (int i = start; i < n; ++i) {
            if (isPalindrome(s, start, i)) {
                currentPath.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, currentPath, result);
                currentPath.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> currentPath;
        vector<vector<string>> result;
        backtrack(s, 0, currentPath, result);
        return result;
    }
};

