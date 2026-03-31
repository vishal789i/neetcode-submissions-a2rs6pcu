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
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, INT_MIN, INT_MAX});

        while (not q.empty()) {
            auto node = get<0>(q.front());
            auto lowerLimit = get<1>(q.front());
            auto upperLimit = get<2>(q.front());
            q.pop();

            if (not (node->val < upperLimit and node->val > lowerLimit)) {
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
