# ref: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/solutions/2588015/java-c-python-bit-solution-with-explanation

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        # last[i]: the nearest index of ith bit of 1 among all the numbers
        last = [0 for _ in range(32)]
        n = len(nums)
        ans = [0 for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(32):
                if nums[i] & (1 << j):  # jth bit of nums[i] is 1
                    last[j] = i
            ans[i] = max(1, max(last) - i + 1)
        return ans

