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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);

        ListNode *prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode *a = prev->next;
            ListNode *b = a->next;

            
            a->next = b->next;
            b->next = a;
            prev->next = b;
            
            prev = a;
        }

        return dummy.next;
    }
};