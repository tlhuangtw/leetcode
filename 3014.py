class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        if n <= 8:
            return n
        elif 9 <= n <= 16:
            return 8 + 2 * (n - 8)
        elif 17 <= n <= 24:
            return 8 + 16 + 3 * (n - 16)
        else:
            return 8 + 16 + 24 + 4 * (n - 24)

