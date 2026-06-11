class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](auto self, int i) -> int {
            if (parent[i] != i) {
                parent[i] = self(self, parent[i]);
            }
            return parent[i];
        };

        for (const auto& edge : edges) {
            int rootA = find(find, edge[0]);
            int rootB = find(find, edge[1]);
            if (rootA == rootB) {
                return edge;
            }
            parent[rootA] = rootB;
        }

        return {};
    }
};

