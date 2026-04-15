# ref: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/solutions/7540838/1-by-la_castille-ymk5

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        first = second = 51
        for i in range(1, len(nums)):
            if nums[i] < first:
                second = first
                first = nums[i]
            elif first <= nums[i] <= second:
                second = nums[i]
        return nums[0] + first + second

