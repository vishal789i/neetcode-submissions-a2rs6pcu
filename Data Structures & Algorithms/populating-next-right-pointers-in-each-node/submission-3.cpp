/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (not root) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        vector<vector<Node*>> levels;
        while (not q.empty()) {
            int size = q.size();
            levels.push_back(vector<Node*>());
            while (size--) {
                auto cur = q.front();
                q.pop();
                levels.back().push_back(cur);
                if (cur->left) {
                    q.push(cur->left);
                }

                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        map<Node*, Node*> node2NextNode;
        for (const vector<Node*>& l : levels) {
            for (int i = 0; i < l.size() - 1; ++i) {
                node2NextNode[l[i]] = l[i + 1];
            }

            node2NextNode[l.back()] = nullptr;
        }

        function<void(Node*)> dfs = [&] (Node* cur) {
            if (not cur) {
                return;
            }

            cur->next = node2NextNode[cur];
            dfs(cur->left);
            dfs(cur->right);
        };

        dfs(root);
        return root;
    }
};