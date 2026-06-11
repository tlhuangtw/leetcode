class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> backup = dist;

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (backup[u] != INT_MAX) {
                    dist[v] = min(dist[v], backup[u] + price);
                }
            }
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};

