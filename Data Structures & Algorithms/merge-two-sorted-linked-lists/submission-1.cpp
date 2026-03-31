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
    ListNode* mergeTwoLists(ListNode* h1Ptr, ListNode* h2Ptr) {
        ListNode dummyNode;
        ListNode* tailPtr = &dummyNode;
        while (h1Ptr != nullptr and h2Ptr != nullptr) {
            if (h1Ptr->val <= h2Ptr->val) {
                tailPtr->next = h1Ptr;
                h1Ptr = h1Ptr->next;
            } else {
                tailPtr->next = h2Ptr;
                h2Ptr = h2Ptr->next;
            }

            tailPtr = tailPtr->next;
        }

        if (h1Ptr == nullptr) {
            tailPtr->next = h2Ptr;
        } else {
            tailPtr->next = h1Ptr;
        }

        return dummyNode.next;
    }
};
