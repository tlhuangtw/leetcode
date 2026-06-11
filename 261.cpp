class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&] (auto self, int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = self(self, parent[i]);
        };

        for (const auto& edge : edges) {
            int rootA = find(find, edge[0]);
            int rootB = find(find, edge[1]);
            if (rootA == rootB) {
                return false;
            }
            parent[rootA] = rootB;
        }

        return true;
    }
};

