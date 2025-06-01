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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* head_l1 {l1};
        ListNode* prev_l1 {l1};

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        while(l1 || l2) {
            if(!(carry || l2))
                break;
            sum = carry;
            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;
            
            // if list l1 is finished and there are still element in the l2
            // steal resources from l2 and connect at the end of l1
            if (!l1) {
                prev_l1->next = l2;
                l1 = l2;
                l2 = nullptr;
            }

            carry = sum / 10;
            l1 -> val = sum % 10;
            
            prev_l1 = l1;
            l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
            prev_l1->next = new ListNode(carry);

        return head_l1;
    }
};