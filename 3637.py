# ref: https://leetcode.com/problems/trionic-array-i/solutions/7546967/track-the-peak-and-valley-by-la_castille-0g4e

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)

        i = 1
        while i < n and nums[i - 1] < nums[i]:
            i += 1
        p = i - 1

        while i < n and nums[i - 1] > nums[i]:
            i += 1
        q = i - 1

        while i < n and nums[i - 1] < nums[i]:
            i += 1
        right = i - 1

        return p != 0 and p != q and right != q and right == n - 1

