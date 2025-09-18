# ref: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/solutions/6786999/beats-80-beginner-friendly-explanation-python-only

class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0
        len_s = len(s)
        for i in range(len_s):
            freq = collections.defaultdict(int)
            for j in range(i, len_s):
                freq[s[j]] += 1
                freq_values = freq.values()
                ans += max(freq_values) - min(freq_values)

        return ans

