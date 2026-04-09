# ref: https://leetcode.com/problems/binary-gap/solutions/7597944/binary-gap-by-la_castille-22cn

class Solution:
    def binaryGap(self, n: int) -> int:
        ans, cur = 0, 0
        while n % 2 == 0:
            n //= 2
        if n == 1:  # there is only one '1'
            return 0
        while n > 0:
            if n % 2 == 0:
                cur += 1
            else:
                ans = max(cur, ans)
                cur = 0
            n //= 2
        return ans + 1

