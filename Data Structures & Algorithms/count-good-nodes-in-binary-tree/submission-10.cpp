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
    int goodNodes(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&] (TreeNode* root, int maxVal) {
            if (not root) {
                return 0;
            }

            int res = 0;
            if (root->val >= maxVal) {
                res += 1;
                maxVal = root->val;
            }

            return res + dfs(root->left, maxVal) + dfs(root->right, maxVal);
        };

        return dfs(root, root->val);
    }
};
