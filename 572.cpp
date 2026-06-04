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
    string serialize(TreeNode* node) {
        if (node == nullptr) {
            return "#";
        }
        return "," + to_string(node->val) + serialize(node->left) + serialize(node->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serializedRoot = serialize(root);
        string serializedSubRoot = serialize(subRoot);
        return serializedRoot.find(serializedSubRoot) != string::npos;
    }
};

