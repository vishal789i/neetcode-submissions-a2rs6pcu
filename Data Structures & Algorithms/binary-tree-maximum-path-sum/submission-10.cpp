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
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if (not root) {
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);
        int temp = max(root->val, root->val + max(l, r));
        res = max({res, temp, root->val + l + r});
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
