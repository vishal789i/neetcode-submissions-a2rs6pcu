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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isPastNull = false;
        while (not q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == nullptr) {
                isPastNull = true;
            } else if (isPastNull) {
                return false;
            } else {
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return true;
    }
};