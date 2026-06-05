/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }

        int good = 0;
        if (node->val >= maxSoFar) {
            good++;
            maxSoFar = node->val;
        }

        return good + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

