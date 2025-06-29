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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slower = head;
        ListNode* fast = head;
    
        while (fast && fast->next) {
            fast = fast->next ? fast->next->next : fast->next;
            prev = slower;
            slower = slower->next;
        }
        if (prev) {
            prev->next = slower->next; 
            // for some reason leetcode causes runtime error while deleting single element list
            delete slower; 
        }
        else head = nullptr;        
        return head;
    }
};