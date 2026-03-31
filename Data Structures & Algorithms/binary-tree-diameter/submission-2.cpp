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
    int diameterOfBinaryTree(TreeNode* root) {
        auto getHeight = [&] (TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;
            while (not q.empty()) {
                auto levelSize = q.size();
                for (int i = 0; i < levelSize; ++i) {
                    auto currRoot = q.front();
                    q.pop();
                    if (currRoot->left != nullptr) {
                        q.push(currRoot->left);
                    }
                    
                    if (currRoot->right != nullptr) {
                        q.push(currRoot->right);
                    }
                }
                level++;
            }

            return level;
        };

        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            auto currRoot = q.front();
            q.pop();

            if (currRoot->left != nullptr) {
                q.push(currRoot->left);
            }

            if (currRoot->right != nullptr) {
                q.push(currRoot->right);
            }

            auto leftHeight = getHeight(currRoot->left);
            auto rightHeight = getHeight(currRoot->right);
            res = max(res, leftHeight + rightHeight);
        }

        return res;
    }
};
