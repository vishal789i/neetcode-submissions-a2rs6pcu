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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        auto cur = root;
        auto prev = cur;
        while (cur) {
            prev = cur;
            if (val < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (val < prev->val) {
            prev->left = new TreeNode(val);
        } else {
            prev->right = new TreeNode(val);
        }

        return root;
    }
};