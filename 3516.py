class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dist_xz = abs(x - z)
        dist_yz = abs(y - z)
        if dist_xz < dist_yz:
            return 1
        elif dist_yz < dist_xz:
            return 2
        else:
            return 0

