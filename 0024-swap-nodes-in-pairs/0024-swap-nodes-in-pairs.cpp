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

        ListNode dummy;
        dummy.next = head;


        ListNode *prev, *first, *second;
        prev = &dummy;
        first = head;
        second = head->next;

        while (second != nullptr) {
            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            first = first->next;
            if (first)
                second = first->next;
            else 
                second = nullptr;
        }

        return dummy.next;
    }
};