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
        map<Node*, Node*> old2New;

        function<Node*(Node*)> dfs = [&] (Node* node) -> Node*{
            if (node == nullptr) {
                return nullptr;
            }

            if (old2New.count(node)) {
                return old2New[node];
            }

            auto newNode = new Node(node->val);
            old2New[node] = newNode;

            for (auto neighbor: node->neighbors) {
                newNode->neighbors.push_back(dfs(neighbor));
            }

            return newNode;
        };

        dfs(node);
        return old2New[node];
    }
};
