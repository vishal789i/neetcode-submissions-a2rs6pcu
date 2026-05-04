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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, int, int)> f = [&] (TreeNode* cur, int min, int max) {
            if (cur == nullptr) {
                return true;
            }

            if (cur->val <= min or cur->val >= max) {
                return false;
            }

            return f(cur->left, min, cur->val) and f(cur->right, cur->val, max);
        };

        return f(root, INT_MIN, INT_MAX);
    }
};
