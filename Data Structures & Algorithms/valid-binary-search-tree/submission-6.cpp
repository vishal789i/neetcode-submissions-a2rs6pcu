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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, INT_MIN, INT_MAX});
        while (not q.empty()) {
            auto [node, lowerLimit, upperLimit] = q.front();
            q.pop();

            if (node->val <= lowerLimit or node->val >= upperLimit) {
                return false;
            }

            if (node->left) {
                q.push({node->left, lowerLimit, node->val});
            }

            if (node->right) {
                q.push({node->right, node->val, upperLimit});
            }
        }

        return true;
    }
};