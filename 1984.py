class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 100001
        for r in range(k - 1, len(nums)):
            ans = min(ans, nums[r] - nums[r - (k - 1)])
        return ans

