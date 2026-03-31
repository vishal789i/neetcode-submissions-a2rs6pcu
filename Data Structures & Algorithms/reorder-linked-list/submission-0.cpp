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
    void reorderList(ListNode *firstListPtr) {
        ListNode *slowPtr = firstListPtr, *fastPtr = firstListPtr;
        while (fastPtr and fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }


        // slow at mid
        ListNode* secondListPtr = slowPtr->next;
        
        // terminate 1st list
        slowPtr->next = nullptr;

        ListNode *prevPtr = nullptr, *currPtr = secondListPtr;
        while (currPtr) {
            auto temp = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = temp;
        }

        secondListPtr = prevPtr;

        ListNode *tempPtr = nullptr;
        while (firstListPtr and secondListPtr) {
            auto temp1 = firstListPtr->next;
            auto temp2 = secondListPtr->next;
            firstListPtr->next = secondListPtr;
            secondListPtr->next = temp1;
            firstListPtr = temp1;
            secondListPtr = temp2;
        }
    }
};
