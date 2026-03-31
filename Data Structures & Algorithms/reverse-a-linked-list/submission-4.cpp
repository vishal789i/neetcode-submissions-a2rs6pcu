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
    ListNode* reverseList(ListNode* cur) {
        ListNode* res = nullptr;
        function<void(ListNode*, ListNode*)> dfs = [&] (ListNode* prev, ListNode* cur) {
            if (cur == nullptr) {
                res = prev;
                return;
            }
            
            auto nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            dfs(cur, nextNode);
        };

        dfs(nullptr, cur);
        return res;
    }
};
