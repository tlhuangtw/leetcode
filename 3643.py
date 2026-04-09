class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        x1, x2 = x, x + k - 1
        while x1 < x2:
            for y1 in range(y, y + k):
                grid[x1][y1], grid[x2][y1] = grid[x2][y1], grid[x1][y1]
            x1 += 1
            x2 -= 1
        return grid

