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
    int maxDepth(TreeNode* root) {
        function<void(TreeNode*, int, int&)> dfs = [&] (TreeNode* root, int currH, int& maxH) {
            if (root == nullptr) {
                return;
            }

            if (currH > maxH) {
                maxH = currH;
            }
            dfs(root->left, currH + 1, maxH);
            dfs(root->right, currH + 1, maxH);
        };

        int maxH = 0;
        dfs(root, 1, maxH);
        return maxH;
    }
};
