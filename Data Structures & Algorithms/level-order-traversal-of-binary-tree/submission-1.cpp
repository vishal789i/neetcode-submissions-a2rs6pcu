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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            int levelSize = q.size();
            vector<int> levelVals;
            for (int i = 0; i < levelSize; ++i) {
                auto node = q.front();
                q.pop();
                if (node == nullptr) {
                    continue;
                }

                levelVals.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (levelVals.size() > 0) {
                res.push_back(levelVals);
            }
        }

        return res;
    }
};
