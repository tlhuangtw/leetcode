class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        result.reserve(m * n);
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 1;

        for (int i = 0; i < m * n; ++i) {
            result.push_back(matrix[x][y]);
            matrix[x][y] = 101;
            if (x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n || matrix[x + dx][y + dy] == 101) {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
            x += dx;
            y += dy;
        }

        return result;
    }
};

