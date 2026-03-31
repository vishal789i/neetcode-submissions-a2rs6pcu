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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int maxLevel = -1;
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* root, int curLevel) {
            if (root == nullptr) {
                return;
            }

            if (curLevel > maxLevel) {
                res.push_back(root->val);
                maxLevel = curLevel;
            }

            dfs(root->right, curLevel + 1);
            dfs(root->left, curLevel + 1);
        };

        dfs(root, 0);
        return res;
    }
};
