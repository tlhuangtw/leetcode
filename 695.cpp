class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int row, int col) {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        return 1 + dfs(grid, r - 1, c, row, col) +
                   dfs(grid, r, c - 1, row, col) +
                   dfs(grid, r, c + 1, row, col) +
                   dfs(grid, r + 1, c, row, col);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int maxArea = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, row, col));
                }
            }
        }

        return maxArea;
    }
};

