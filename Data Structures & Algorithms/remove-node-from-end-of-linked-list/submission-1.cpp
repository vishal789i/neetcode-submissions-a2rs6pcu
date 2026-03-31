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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        auto traversePtr = head;
        while (traversePtr) {
            l++;
            traversePtr = traversePtr->next;
        }

        if (l <= 1) {
            return nullptr;
        }

        int k = l - n - 1;
        if (l - n == 0) {
            return head->next;
        }
        
        traversePtr = head;
        for (int i = 0; i < l; ++i) {
            if (i == k) {
                traversePtr->next = traversePtr->next->next;
                break;
            }

            traversePtr = traversePtr->next;
        }

        return head;
    }
};
