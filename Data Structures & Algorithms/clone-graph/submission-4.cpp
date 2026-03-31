/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (not node) {
            return nullptr;
        }
        map<Node*, Node*> old2Copy;
        old2Copy[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while (not q.empty()) {
            auto node = q.front();
            q.pop();

            for (auto nei : node->neighbors) {
                if (not old2Copy.count(nei)) {
                    old2Copy[nei] = new Node(nei->val);
                    q.push(nei);
                }

                old2Copy[node]->neighbors.push_back(old2Copy[nei]);
            }
        }
        return old2Copy[node];
    }
};
