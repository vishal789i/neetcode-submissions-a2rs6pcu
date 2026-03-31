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
        map<Node*, Node*> old2NewMap;

        function<Node*(Node*)> dfs = [&] (Node* node) -> Node* {
            if (not node) {
                return nullptr;
            }

            if (old2NewMap.count(node)) {
                return old2NewMap[node];
            }

            Node* newNode = new Node(node->val);
            old2NewMap[node] = newNode;

            for (auto* nei: node->neighbors) {
                newNode->neighbors.push_back(dfs(nei));
            }

            return newNode;
        };

        return dfs(node);
    }
};
