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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(-1, head);
        ListNode* nodeBeforeLeft = &dummy;
        // Move nodeBeforeLeft to (left-1)th node
        for (int i = 1; i < left; ++i) {
            nodeBeforeLeft = nodeBeforeLeft->next;
        }

        ListNode* leftNode = nodeBeforeLeft->next;
        ListNode* cur = leftNode;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        int count = right - left + 1;
        // Reverse exactly (right-left+1) nodes
        while (count--) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        nodeBeforeLeft->next = prev;
        leftNode->next = cur;
        return dummy.next;
    }
};