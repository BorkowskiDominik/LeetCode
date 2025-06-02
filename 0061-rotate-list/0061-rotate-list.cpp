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
        ListNode *new_end, *ptr=head->next;
        
        int list_len = 1;
        
        while (ptr!=head) {
            if (!ptr->next) {
                ptr->next = head;
                new_end = ptr;
            }
            list_len++;
            ptr = ptr->next;
        }

        int rotations = list_len - (k % list_len);
        while (rotations) {
            new_end=new_end->next;
            rotations--;
        }

        head = new_end->next;
        new_end->next = nullptr;
        return head;
    }
};