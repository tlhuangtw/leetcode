class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        min_v, max_v = min(nums), max(nums)
        num_list = [n for n in range(min_v, max_v + 1)]
        for _, n in enumerate(nums):
            num_list[n - min_v] = 0
        return sorted(num_list)[len(nums):]

