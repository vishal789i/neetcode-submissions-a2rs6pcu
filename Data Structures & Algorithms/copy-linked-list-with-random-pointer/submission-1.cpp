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
    map<Node*, Node*> old2New;
    Node* copyRandomList(Node* head) {
        if (not head) {
            return head;
        }

        auto copy = new Node(head->val);
        old2New[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = old2New[head->random];
        return copy;
    }
};
