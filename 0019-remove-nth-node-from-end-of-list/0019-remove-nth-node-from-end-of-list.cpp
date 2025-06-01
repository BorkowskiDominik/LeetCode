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
        ListNode dummy(0);
        dummy.next = head;

        ListNode* ptr = &dummy;
        ListNode* prev_to_removed = &dummy;

        for ( int i = 0; i <= n; ++i )
            ptr = ptr->next;

        while ( ptr ) {
            prev_to_removed = prev_to_removed->next;
            ptr = ptr->next;
        }
        
        ListNode* removed = prev_to_removed->next;
        prev_to_removed->next = removed->next;
        
        delete removed;
        return dummy.next;
    }
};