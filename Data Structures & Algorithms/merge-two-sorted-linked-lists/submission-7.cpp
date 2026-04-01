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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        auto traverse = &dummy;
        while (l1 and l2) {
            if (l1->val <= l2->val) {
                traverse->next = l1;
                l1 = l1->next;
            } else {
                traverse->next = l2;
                l2 = l2->next;
            }

            traverse = traverse->next;
        }

        if (l1) {
            traverse->next = l1;
        }

        if (l2) {
            traverse->next = l2;
        }

        return dummy.next;
    }
};
