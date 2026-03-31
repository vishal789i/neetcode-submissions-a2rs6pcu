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
    void dfs(TreeNode* node, int level, int& maxLevel, vector<int>& res) {
        if (node == nullptr) {
            return;
        }

        if (level > maxLevel) {
            res.push_back(node->val);
            maxLevel = level;
        }
        
        dfs(node->right, level + 1, maxLevel, res);
        dfs(node->left, level + 1, maxLevel, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level = 0, maxLevel = -1;
        dfs(root, level, maxLevel, res);
        return res;
    }
};
