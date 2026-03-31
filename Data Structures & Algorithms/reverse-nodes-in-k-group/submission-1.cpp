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
    ListNode* getKth(ListNode* cur, int k) {
        while (cur and k > 0) {
            cur = cur->next;
            k--;
        }

        return cur;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        auto groupPrev = &dummy;

        while (true) {
            auto kth = getKth(groupPrev, k);
            if (not kth) {
                break;
            }

            auto groupNext = kth->next;
            
            auto prev = groupNext;
            auto cur = groupPrev->next;
            while (cur != groupNext) {
                auto temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }

            auto temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy.next;
    }
};
