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
    int res = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int hl = dfs(root->left);
        int hr = dfs(root->right);

        res = max(res, hl + hr);

        return 1 + max(hl, hr);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
