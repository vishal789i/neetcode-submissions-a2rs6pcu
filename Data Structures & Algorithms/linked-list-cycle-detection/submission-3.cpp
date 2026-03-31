/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        set<ListNode*> vis;
        ListNode* traverse = head;
        while (traverse->next) {
            if (vis.count(traverse)) {
                return true;
            }
            vis.insert(traverse);
            traverse = traverse->next;
        }
        return false;
    }
};
