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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
                // delete head;
                head = prev->next;
                continue;
            }
            prev = prev->next;
            head = prev->next;
        }
        return dummy.next;
    }
};