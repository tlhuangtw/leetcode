# ref: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/solutions/5846330/java-c-python-1-line-o-logk

class Solution:
    def kthCharacter(self, k: int) -> str:
        return chr(ord('a') + (k - 1).bit_count())

