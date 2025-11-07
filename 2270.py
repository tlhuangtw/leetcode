class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        cur_sum = 0
        n = len(nums)
        ans = 0
        for i in range(n - 1):
            cur_sum += nums[i]
            if cur_sum >= total - cur_sum:
                ans += 1
        return ans

