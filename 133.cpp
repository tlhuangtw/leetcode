/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> cloneMap;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        cloneMap[node] = new Node(node->val);
        for (const auto& neighbor : node->neighbors) {
            cloneMap[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneMap[node];
    }
};

