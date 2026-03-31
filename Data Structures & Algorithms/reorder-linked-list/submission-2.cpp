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
        vector<ListNode*> nodes;
        auto cur = head;
        while (cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            auto nextI = nodes[i]->next;
            nodes[i]->next = nodes[j];
            nodes[j]->next = nextI;
            i++;
            j--;
        }

        nodes[i]->next = nullptr;
    }
};
