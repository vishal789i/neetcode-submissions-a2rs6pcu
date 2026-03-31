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
        stack<int> stk;
        auto cur = head;
        while (cur) {
            stk.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (not stk.empty()) {
            if (stk.top() != cur->val) {
                return false;
            }
            
            stk.pop();
            cur = cur->next;
        }

        return true;
    }
};