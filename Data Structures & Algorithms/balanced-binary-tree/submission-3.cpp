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
    bool res = true;
    int solve(TreeNode* node) {
        if (not node) {
            return 0;
        }

        int lh = solve(node->left);
        int rh = solve(node->right);
        if (abs(lh - rh) > 1) {
            res = false;
            return 0;
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        solve(root);
        return res;
    }
};
