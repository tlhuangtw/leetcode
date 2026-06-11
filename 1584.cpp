class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        int minCost = 0;

        minDist[0] = 0;
        for (int i = 0; i < n; ++i) {
            int cur = -1;

            for (int j = 0; j < n; ++j) {
                if (!inMST[j] && (cur == -1 || minDist[j] < minDist[cur])) {
                    cur = j;
                }
            }

            inMST[cur] = true;
            minCost += minDist[cur];

            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!inMST[nextNode]) {
                    int dist = abs(points[cur][0] - points[nextNode][0]) + abs(points[cur][1] - points[nextNode][1]);
                    minDist[nextNode] = min(minDist[nextNode], dist);
                }
            }
        }

        return minCost;
    }
};

