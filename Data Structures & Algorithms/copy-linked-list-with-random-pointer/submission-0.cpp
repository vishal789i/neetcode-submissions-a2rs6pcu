/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> old2Copy;
        old2Copy[NULL] = NULL;

        auto curr = head;
        while (curr) {
            auto copyNode = new Node(curr->val);
            old2Copy[curr] = copyNode;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            auto copy = old2Copy[curr];
            copy->next = old2Copy[curr->next];
            copy->random = old2Copy[curr->random];
            curr = curr->next;
        }

        return old2Copy[head];
    }
};
