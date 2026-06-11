class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses);

        for (const auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            inDeg[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);

            for (int neighbor : adj[cur]) {
                if (--inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};

