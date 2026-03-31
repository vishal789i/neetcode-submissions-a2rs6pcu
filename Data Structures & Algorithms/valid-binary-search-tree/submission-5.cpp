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
    bool dfs(TreeNode* node, int lowerLimit, int upperLimit) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= lowerLimit or node->val >= upperLimit) {
            return false;
        }

        return dfs(node->left, lowerLimit, node->val) and dfs(node->right, node->val, upperLimit);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
