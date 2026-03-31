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
        vector<vector<int>> ans;

        queue<TreeNode*> processingQ;
        processingQ.push(root);
        while (not processingQ.empty()) {
            vector<int> level;
            auto size = processingQ.size();
            for (int i = 0; i < size; ++i) {
                auto node = processingQ.front();
                processingQ.pop();   
                if (node) {
                    level.push_back(node->val);
                    if (node->left) {
                        processingQ.push(node->left);
                    }
                    
                    if (node->right) {
                        processingQ.push(node->right);
                    }
                }
            }
            if (not level.empty()) {
                ans.push_back(level);
            }
        }

        return ans;
    }
};
