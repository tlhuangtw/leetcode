# ref: https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4840098/c-c-python-freq-array-counting-0ms-beats-100

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = [0 for _ in range(101)]
        max_f = 0
        for n in nums:
            freq[n] += 1
            max_f = max(max_f, freq[n])
        ans = 0
        for f in freq:
            if f == max_f:
                ans += f
        return ans

