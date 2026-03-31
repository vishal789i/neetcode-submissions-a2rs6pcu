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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (not root and not subRoot) {
            return true;
        }

        if (root and subRoot and root->val == subRoot->val) {
            return isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right);
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (not subRoot) {
            return true;
        }

        if (not root) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
