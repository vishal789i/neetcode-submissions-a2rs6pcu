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
    map<Node*, Node*> old2Copy;
public:
    Node* cloneGraph(Node* node) {
        if (not node) {
            return nullptr;
        }

        if (old2Copy[node]) {
            return old2Copy[node];
        }

        auto newNode = new Node(node->val);
        old2Copy[node] = newNode;
        for (auto nei : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(nei));
        }

        return old2Copy[node];
    }
};
