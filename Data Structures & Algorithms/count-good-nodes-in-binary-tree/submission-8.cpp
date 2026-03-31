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
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        int res = 0;
        while (not q.empty()) {
            auto [node, maxVal] = q.front();
            q.pop();

            if (node->val >= maxVal) {
                res += 1;
                maxVal = node->val;
            }

            if (node->left) {
                q.push({node->left, maxVal});
            }

            if (node->right) {
                q.push({node->right, maxVal});
            }
        }
        return res;
    }
};
