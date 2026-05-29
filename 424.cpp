class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> count = {};
        int maxLen = 0;
        int left = 0;
        int maxFreq = 0;
        int n = s.size();

        for (int right = 0; right < n; ++right) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

