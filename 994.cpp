class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) {
            return 0;
        }

        int minutes = 0;
        int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            bool rottedThisMinute = false;
            int qSize = q.size();

            for (int i = 0; i < qSize; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int newX = x + d[0];
                    int newY = y + d[1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        rottedThisMinute = true;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        freshCount--;
                    }
                }
            }

            if (rottedThisMinute) {
                minutes++;
            }
        }

        return freshCount == 0 ? minutes : -1;
    }
};

