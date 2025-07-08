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
    ListNode* splitList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // fast = slow;
        // slow = slow->next;
        // fast->next = nullptr; //optional
        return slow->next;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        // idea: 
        // split by half, reverse second half and compare
        ListNode* half = splitList(head);
        half = reverse(half);
        ListNode* ptr = half;
        while (ptr) {
            if (ptr->val != head->val)
                return false;
            ptr = ptr->next;
            head = head->next;
        }

        // optionally restore original state:
        reverse(half);
        return true;
    }
};