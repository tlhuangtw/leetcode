# ref: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/solutions/5207565/double-xor

class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = 0
        num_set = set(nums)
        print(num_set)
        for n in nums:
            ans ^= n
        for n in num_set:
            ans ^= n
        return ans

