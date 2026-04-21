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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<std::string> serializedVec;
        function<void(TreeNode*)> dfs = [&] (TreeNode* node) {
            if (node == nullptr) {
                serializedVec.push_back("N");
                return;
            }

            serializedVec.push_back(to_string(node->val));
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        string res;
        for (auto& e: serializedVec) {
            res += e + ",";
        }

        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        vector<string> serializedVec;
        while (getline(ss, word, ',')) {
            serializedVec.push_back(word);
        }

        int i = 0;
        function<TreeNode*()> dfs = [&] () -> TreeNode* {
            if (serializedVec[i] == "N") {
                i++;
                return nullptr;
            }

            return new TreeNode(stoi(serializedVec[i++]), dfs(), dfs());
        };

        return dfs();
    }
};
