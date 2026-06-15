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
    void reorderList(ListNode* head) {
        auto fast = head, slow = head;
        while (slow and fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto secondListHead = slow->next;
        slow->next = nullptr;
        ListNode *cur = secondListHead, *prev = nullptr;
        while (cur) {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        secondListHead = prev;
        cur = head;
        while (cur and secondListHead) {
            auto curNext = cur->next;
            auto secondListNext = secondListHead->next;
            cur->next = secondListHead;
            secondListHead->next = curNext;
            cur = curNext;
            secondListHead = secondListNext;
        }
    }
};
