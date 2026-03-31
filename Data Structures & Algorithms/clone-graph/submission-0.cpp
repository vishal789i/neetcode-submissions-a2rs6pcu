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
        if (node == nullptr) {
            return nullptr;
        }

        map<Node*, Node*> old2New;
        old2New[node] = new Node(node->val);
        
        auto&& bfs = [&] (Node* node) {
            queue<Node*> q;
            q.push(node);
            while (not q.empty()) {
                auto node = q.front();
                q.pop();
                for (auto neighbor: node->neighbors) {
                    if (old2New.find(neighbor) == old2New.end()) {
                        old2New[neighbor] = new Node(neighbor->val);
                        q.push(neighbor);
                    }

                    old2New[node]->neighbors.push_back(old2New[neighbor]);
                }
            }
        };

        bfs(node);
        return old2New[node];
    }
};
