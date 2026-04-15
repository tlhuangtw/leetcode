class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        a, b, c, d = s1[0], s1[2], s2[0], s2[2]
        e, f, g, h = s1[1], s1[3], s2[1], s2[3]
        return (a == c and b == d or a == d and b == c) and (e == g and f == h or e == h and f == g)

