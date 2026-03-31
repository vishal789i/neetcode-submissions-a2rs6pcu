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
    bool isPalindrome(ListNode* head) {
        function<bool(ListNode*)> dfs = [&] (ListNode* cur) {
            if (cur == nullptr) {
                return true;
            }

            auto isNextNodeValidPalindrome = dfs(cur->next);
            if (not isNextNodeValidPalindrome) {
                return false;
            }
            // we are now at end
            if (head->val != cur->val) {
                return false;
            }

            head = head->next;
            return true;
        };

        return dfs(head);
    }
};