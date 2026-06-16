class Solution {
private:
    int dp[100][100][100];
    int calculateMaxPoints(vector<int>& boxes, int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }

        int originalI = i;
        int originalK = k;

        while (i + 1 <= j && boxes[i + 1] == boxes[i]) {
            i++;
            k++;
        }

        int res = (k + 1) * (k + 1) + calculateMaxPoints(boxes, i + 1, j, 0);

        for (int m = i + 1; m <= j; ++m) {
            if (boxes[m] == boxes[i]) {
                res = max(res, calculateMaxPoints(boxes, i + 1, m - 1, 0) + calculateMaxPoints(boxes, m, j, k + 1));
            }
        }

        return dp[originalI][j][originalK] = res;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), 0);
        return calculateMaxPoints(boxes, 0, n - 1, 0);
    }
};

