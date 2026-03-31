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
    int kthSmallest(TreeNode* root, int k) {
        if (not root) {
            return -1;
        }
        
        vector<int> res;
        stack<TreeNode*> stk;
        auto cur = root;
        while (cur or not stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            if (not stk.empty()) {
                cur = stk.top();
                stk.pop();
                k--;
                if (k == 0) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }
        return -1;
    }
};
