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
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
    
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* n) {
        ListNode* prev = nullptr;
        ListNode* next = n->next;

        while (n) {
            next = n->next;
            n->next = prev;
            prev = n;
            n = next;
        }

        return prev;
    }

public: 
    int pairSum(ListNode* head) { 
        ListNode* middle = findMiddle(head);
        middle = reverse(middle);
        int maxSum {};
        while (middle) {
            maxSum = std::max(maxSum, middle->val + head->val);
            head = head->next;
            middle = middle->next;
        }
        return maxSum;
    }
};


// Taki ciekawy pomysł miałem, ale słabo wydajny
// pół rekurencyjnie, ale za to bez modyfikowania oryginalnej listy
// class Solution {
//     ListNode* findMiddle(ListNode* head) {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }

//     void maxSumRecursive(ListNode* head, ListNode*& middle, int& maxSum)
//     {
//         if (head == middle) return;
//         maxSumRecursive(head->next, middle, maxSum);
//         maxSum = std::max(maxSum, head->val + middle->val);
//         middle = middle->next;
//     }

// public:
//     int pairSum(ListNode* head) {
//         int maxSum {};
//         ListNode* middle = findMiddle(head);
//         maxSumRecursive(head, middle, maxSum);
//         return maxSum;
//     }
// };