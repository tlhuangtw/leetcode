class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        ans = ""
        sign = "" if num > 0 else "-"
        num = abs(num)
        while num > 0:
            ans += str(num % 7)
            num //= 7
        return sign + ans[::-1]

