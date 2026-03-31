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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *prev = nullptr;
        while (cur) {
            if (cur->val == val) {
                if (prev == nullptr) {
                    auto temp = head;
                    head = head->next;
                    delete temp;
                    cur = head;
                } else {
                    auto temp = cur;
                    prev->next = cur->next;
                    cur = cur->next;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};