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

enum class ALGORITHM {ITER, RECURSIVE};
constexpr auto ALGO = ALGORITHM::ITER;

class Solution {
    ListNode* reverseListIterative(ListNode* head);
    ListNode* reverseListRecursive(ListNode* head);
    ListNode* reverse(ListNode* prev, ListNode* curr);

public:
    ListNode* reverseList(ListNode* head) {
        if (ALGO == ALGORITHM::ITER)
            return reverseListIterative(head);

        else if (ALGO == ALGORITHM::RECURSIVE)
            return reverseListRecursive(head);

        else // unknown algorithm
            return head;
    }
};

ListNode* Solution::reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* Solution::reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    auto new_head = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}