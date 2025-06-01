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
        if (left == right || !head) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* l_prev = &dummy;

        // find l_prev (one before "left")
        for (int i = 1; i < left; ++i) {
            l_prev = l_prev->next;
        }

        // reverse pointers
        ListNode* curr = l_prev->next;
        ListNode* prev = nullptr;

        for (int i = 0; i <= right - left; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect with the list
        l_prev->next->next = curr; // reconnect first reversed element to first not changed element on the right
        l_prev->next = prev;       // reconnect l_prev to new reversed list beginning

        return dummy.next;
    }

};