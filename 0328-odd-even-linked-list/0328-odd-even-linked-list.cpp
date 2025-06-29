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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy_even(0);
        ListNode dummy_odd(0);
        ListNode* even = &dummy_even;
        ListNode* odd = &dummy_odd;
        bool is_even = false;
        
        while(head) {
            if (is_even) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;

            is_even = !is_even;
        }

        even->next = nullptr;
        odd->next = dummy_even.next;
        return dummy_odd.next;
    }
};