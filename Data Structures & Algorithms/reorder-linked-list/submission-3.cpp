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
        auto slow = head, fast = head;
        while (slow and fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto secondList = slow->next;
        slow->next = nullptr;
        auto cur = secondList;
        ListNode* prev = nullptr;
        while (cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        secondList = prev;
        cur = head;
        while (cur and secondList) {
            auto nextCur = cur->next;
            auto nextSecondList = secondList->next;
            cur->next = secondList;
            secondList->next = nextCur;
            cur = nextCur;
            secondList = nextSecondList;
        }
    }
};
