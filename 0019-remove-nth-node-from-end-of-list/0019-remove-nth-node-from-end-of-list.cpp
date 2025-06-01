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

        auto f = [&](){ cout << "prev: " << (prev_to_removed ? to_string(prev_to_removed->val) : "null") << " ptr: " << (ptr ? to_string(ptr->val) : "null") << endl; };
        
        for (int i = 0; i <= n; ++i)
            ptr = ptr->next;
        // f();
        while ( ptr ) {
            prev_to_removed = prev_to_removed->next;
            ptr = ptr->next;
            // f();
        }
        
        ListNode* removed = prev_to_removed->next;
        prev_to_removed->next = removed->next;
        
        delete removed;
        return dummy.next;
    }
};