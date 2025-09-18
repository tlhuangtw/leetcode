# ref: https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/7097069/zero-filled-subarrays-100-beat-most-efficient-java-c-c-c-python3-go-js-ts

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        zero_arr_size = 0
        for num in nums:
            # when we encounter a zero, the zero_arr_size increase by one
            # a zero-filled subarray of length n has 1 + 2 + 3 + ... + n sub-subarrays
            if num == 0:
                zero_arr_size += 1
                ans += zero_arr_size
            else:
                zero_arr_size = 0
        return ans

