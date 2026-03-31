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

        map<Node*, Node*> old2Copy;
        auto cur = head;
        while (cur) {
            old2Copy[cur] = new Node(cur->val);
            auto random = cur->random;
            if (random) {
                old2Copy[random] = new Node(random->val);
            }

            cur = cur->next;
        }

        cur = head;
        while (cur) {
            old2Copy[cur]->next = old2Copy[cur->next];
            old2Copy[cur]->random = old2Copy[cur->random];
            cur = cur->next;
        }

        return old2Copy[head];
    }
};
