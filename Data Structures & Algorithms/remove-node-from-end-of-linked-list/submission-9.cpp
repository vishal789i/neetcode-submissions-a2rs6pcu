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
        function<ListNode*(ListNode*)> dfs = [&] (ListNode* head) -> ListNode* {
            if (not head) {
                return nullptr;
            }

            head->next = dfs(head->next);
            n--;
            if (n == 0) {
                return head->next;
            } else {
                return head;
            }
        };

        return dfs(head);
    }
};
