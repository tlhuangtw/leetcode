class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> result;

        for (const auto& point : points) {
            maxHeap.push({point[0] * point[0] + point[1] * point[1], point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

