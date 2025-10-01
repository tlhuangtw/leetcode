# ref: https://leetcode.com/problems/largest-perimeter-triangle/solutions/217988/java-c-python-sort-and-try-biggest

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        size = len(nums)
        for i in range(size - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0

