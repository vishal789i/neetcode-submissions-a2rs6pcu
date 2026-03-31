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
    int diameterOfBinaryTree(TreeNode* root) {
        int res;
        function<int(TreeNode*)> dfs = [&] (TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            int leftHeight = dfs(root->left);
            int rightHeight = dfs(root->right);

            res = max(res, leftHeight + rightHeight);
            return 1 + max(leftHeight, rightHeight);
        };

        dfs(root);
        return res;
    }
};
