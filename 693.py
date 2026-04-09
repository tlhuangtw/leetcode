class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        cur_digit = -1
        while n > 0:
            if n % 2 == cur_digit:
                return False
            cur_digit = n % 2
            n //= 2
        return True

