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
        if (not head) {
            return nullptr;
        }

        auto cur = head;
        while (cur) {
            auto newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }

        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }

            cur = cur->next->next;
        }

        Node dummy(-1);
        auto tail = &dummy;
        cur = head;
        while (cur) {
            auto copy = cur->next;
            cur->next = copy->next;
            tail->next = copy;
            tail = copy;
            cur = cur->next;
        }

        return dummy.next;
    }
};