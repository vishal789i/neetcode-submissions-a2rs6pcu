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
        queue<TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            int levelSize = q.size();

            TreeNode* lastNode = nullptr;
            for (int i = 0; i < levelSize; ++i) {
                auto node = q.front();
                q.pop();

                if (node) {
                    lastNode = node;

                    if (node->left) {
                        q.push(node->left);
                    }

                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }

            if (lastNode) {
                res.push_back(lastNode->val);
            }
        }

        return res;
    }
};
