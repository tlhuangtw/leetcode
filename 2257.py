# ref: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/solutions/6067031/beats-100-video-full-explain-3-approache-q1b8

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        SAFE, IN_SIGHT, OCCUPIED = 0, 1, 2
        grid = [[SAFE] * n for _ in range(m)]
        for x, y in guards:
            grid[x][y] = OCCUPIED
        for x, y in walls:
            grid[x][y] = OCCUPIED

        for gx, gy in guards:
            for dx, dy in [(-1, 0), (0, -1), (0, 1), (1, 0)]:
                x, y = gx, gy
                while True:
                    x += dx
                    y += dy
                    if 0 <= x < m and 0 <= y < n and grid[x][y] != OCCUPIED:
                        grid[x][y] = IN_SIGHT
                    else:
                        break

        return sum(row.count(0) for row in grid)

