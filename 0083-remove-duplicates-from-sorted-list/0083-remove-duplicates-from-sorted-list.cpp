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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* begin = head; 
        ListNode* prev = head;
        head = head->next;
        while (head) {
            if (head->val == prev->val) {
                prev->next = head->next;
                delete head;
                head = prev->next;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return begin; 
    }
};