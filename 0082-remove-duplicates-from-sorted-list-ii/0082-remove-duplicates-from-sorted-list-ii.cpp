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
    void release_memory(ListNode* h) {
        while (h) {
            ListNode* next = h->next;
            delete h;
            h = next;
        }
        
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(777);
        dummy.next = head;

        ListNode* ptr = head;
        ListNode* tail = &dummy;
        
        ListNode* remove_head = new ListNode(888);
        ListNode* remove_tail = remove_head;

        while ( ptr ) {
            bool should_remove = (ptr->val == remove_tail->val) || (ptr->next && ptr->val == ptr->next->val);
            if (should_remove) {
                remove_tail->next = ptr;
                remove_tail = ptr;
            } else {
                tail->next = ptr;
                tail = ptr;
            }
            ptr = ptr->next;
        }
        remove_tail->next = nullptr;
        tail->next = nullptr;
        // release_memory(remove_head);
        return dummy.next;
    }
};