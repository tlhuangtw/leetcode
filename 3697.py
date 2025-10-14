class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        power = 1
        ans = []
        while n > 0:
            if (last_digit := n % 10) > 0:
                ans.append(power * last_digit)
            n //= 10
            power *= 10
        return ans[::-1]

