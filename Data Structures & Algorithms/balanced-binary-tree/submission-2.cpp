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
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        function<int(TreeNode*)> dfs = [&] (TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            int lh = dfs(root->left);
            int rh = dfs(root->right);
            int height = 1 + max(lh, rh);

            if (abs(lh - rh) > 1) {
                isBalanced = false;
            }

            return height;
        };

        dfs(root);
        return isBalanced;
    }
};
