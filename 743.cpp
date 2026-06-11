class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();

            if (time > minTime[node]) {
                continue;
            }

            for (const auto& [neighbor, travelTime] : adj[node]) {
                if (minTime[node] + travelTime < minTime[neighbor]) {
                    minTime[neighbor] = minTime[node] + travelTime;
                    minHeap.push({minTime[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (minTime[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, minTime[i]);
        }

        return ans;
    }
};

