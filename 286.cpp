class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms.empty()) {
            return;
        }

        queue<pair<int, int>> q;
        int m = rooms.size();
        int n = rooms[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int newX = x + d[0];
                int newY = y + d[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && rooms[newX][newY] == 2147483647) {
                    rooms[newX][newY] = rooms[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
};

