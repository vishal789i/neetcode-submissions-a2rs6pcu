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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyNode(0);
        ListNode* traverse = &dummyNode;
        while (list1 and list2) {
            if (list1->val <= list2->val) {
                traverse->next = list1;
                list1 = list1->next;
            } else {
                traverse->next = list2;
                list2 = list2->next;
            }
            traverse = traverse->next;
        }

        list1 ? traverse->next = list1 : traverse->next = list2;

        return dummyNode.next;
    }
};
