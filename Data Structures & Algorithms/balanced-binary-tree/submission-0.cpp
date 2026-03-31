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
    int getHeight(TreeNode* root) {
        if (not root) {
            return 0;
        }

        int leftSubTreeHeight = getHeight(root->left);
        int rightSubTreeHeight = getHeight(root->right);

        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }

    bool isBalanced(TreeNode* root) {
        if (not root) {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1) {
            return isBalanced(root->left) and isBalanced(root->right);
        }
        
        return false;
    }
};
