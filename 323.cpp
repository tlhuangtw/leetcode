class UnionFind {
private:
    vector<int> parent;
public:
    int count;
    UnionFind(int n): count(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    void unite(int i, int j) {
        int rootA = find(i);
        int rootB = find(j);
        if (rootA != rootB) {
            parent[rootA] = rootB;
            count--;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (const auto& edge : edges) {
            uf.unite(edge[0], edge[1]);
        }

        return uf.count;
    }
};

