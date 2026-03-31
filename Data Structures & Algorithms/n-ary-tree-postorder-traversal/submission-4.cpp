/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (not root) {
            return res;
        }

        stack<pair<Node*, bool>> stk;
        stk.push({root, false});
        while (not stk.empty()) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (visited) {
                res.push_back(node->val);
            } else {
                stk.push({node, true});
                auto& children = node->children;
                for (auto it = children.rbegin(); it != children.rend(); ++it) {
                    stk.push({*it, false});
                }
            }
        }
        return res;
    }
};