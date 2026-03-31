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
        auto len = 0;
        auto cur = head;
        while (cur) {
            cur = cur->next;
            len++;
        }

        if (len == 1) {
            return nullptr;
        }

        auto pos = len - n - 1;
        if (pos < 0) {
            return head->next;
        }

        cur = head;
        for (int i = 0; i < len; ++i) {
            if (i == pos) {
                cur->next = cur->next->next;
                break;
            }

            cur = cur->next;
        }

        return head;
    }
};
