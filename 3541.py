# ref: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/7183835/simple-clean-100-beats-easy-explanation-beginner-friendly-efficient
# ref: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/7183861/vowel-mask-freq-no-if-beats-100

class Solution:
    def maxFreqSum(self, s: str) -> int:
        max_consonant_freq = 0
        max_vowel_freq = 0
        d = collections.Counter(s)

        for c, c_freq in d.items():
            if c in "aeiou":
                max_vowel_freq = max(max_vowel_freq, c_freq)
            else:
                max_consonant_freq = max(max_consonant_freq, c_freq)

        return max_vowel_freq + max_consonant_freq

