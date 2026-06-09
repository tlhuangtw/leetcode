class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int row, int col) {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';
        dfs(grid, r - 1, c, row, col);
        dfs(grid, r, c - 1, row, col);
        dfs(grid, r, c + 1, row, col);
        dfs(grid, r + 1, c, row, col);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        int numIsland = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    numIsland++;
                    dfs(grid, i, j, row, col);
                }
            }
        }

        return numIsland;
    }
};

