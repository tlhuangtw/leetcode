class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += expandAroundCenter(s, i, i);
            ans += expandAroundCenter(s, i, i + 1);
        }

        return ans;
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};

