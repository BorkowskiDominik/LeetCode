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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *last=head;
        
        int list_len = 1;
        
        // find last and calc size
        while (last->next) {
            last = last->next;
            list_len++;
        }
    
        // create cycle
        last->next = head; 

        int rotations = list_len - (k % list_len);
        while (rotations) {
            last = last->next;
            rotations--;
        }

        // break cycle
        head = last->next;
        last->next = nullptr;
        return head;
    }
};