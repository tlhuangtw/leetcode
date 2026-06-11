class Solution {
private:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int h, int r, int c) {
        int m = heights.size();
        int n = heights[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < h) {
            return;
        }

        visited[r][c] = true;
        dfs(heights, visited, heights[r][c], r - 1, c);
        dfs(heights, visited, heights[r][c], r, c - 1);
        dfs(heights, visited, heights[r][c], r, c + 1);
        dfs(heights, visited, heights[r][c], r + 1, c);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dfs(heights, pac, heights[0][i], 0, i);
            dfs(heights, atl, heights[m - 1][i], m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            dfs(heights, pac, heights[i][0], i, 0);
            dfs(heights, atl, heights[i][n - 1], i, n - 1);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

