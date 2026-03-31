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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() and inorder.empty()) {
            return nullptr;
        }

        map<int, int> inorderEleMent2IndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderEleMent2IndexMap[inorder[i]] = i;
        }

        int preorderIdx = 0;
        function<TreeNode*(int, int)> build = [&] (int l, int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }

            int rootVal = preorder[preorderIdx++];
            TreeNode* root = new TreeNode(rootVal);
            int inorderIdx = inorderEleMent2IndexMap[rootVal];
            root->left = build(l, inorderIdx - 1);
            root->right = build(inorderIdx + 1, r);
            return root;
        };

        return build(0, preorder.size() - 1);
    }
};