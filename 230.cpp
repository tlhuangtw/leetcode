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
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur != nullptr || !stack.empty()) {
            while (cur != nullptr) {
                stack.push_back(cur);
                cur = cur->left;
            }

            cur = stack.back();
            stack.pop_back();

            k--;
            if (k == 0) {
                return cur->val;
            }

            cur = cur->right;
        }

        return -1;
    }
};

