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

// class Solution {
//     using Node = ListNode;
//     using Slice = pair<Node*, Node*>;

//     Node* _reverse(Node* head, Node* end) {
//         if (!head || head == end) 
//             return head;
//         Node *prev = head, *curr = head->next, *next = nullptr;
//         head->next = end;
        
//         while (curr!=end) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         // cout << "end of reverse" << endl;
//         _print(prev, "rev");
//         return prev;
//     }

//     void _print(Node* s, Node* e) {
//         while(s != e) {
//             cout << s->val << " : ";
//             s = s->next;
//         }
//         cout << s->val << endl;
//     }

//     void _print(Node *s, string prefix = "") {
//         if (!prefix.empty())
//             cout << prefix << " ";
//         while(s) {
//             cout << s->val << " ";
//             s = s->next;
//         }
//         cout << endl;
//     }

//     bool _move_by_k(Node*& ptr, int k) {
//         while(k--) {
//             if (!ptr->next)
//                 return false;
//             ptr = ptr->next;
//         }
//         return true;
//     }
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(k<2 || !head || !head->next) 
//             return head;
//         Node dummy(0);
//         dummy.next = head;
        
//         Node *scout = head;
//         Node *slow = &dummy;

//         while (_move_by_k(scout, k)) {
//             Node* old_start = slow->next;
//             slow->next = _reverse(slow->next, scout);
//             slow = old_start;
//         }

//         return dummy.next;
//     }
// };

class Solution {
    using Node = ListNode;

    Node* _reverse(Node* head, Node* end) {
        if (!head || head == end) 
            return head;
        Node *prev = head, *curr = head->next, *next = nullptr;
        head->next = end;

        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* _get_kth(Node* curr, int k) {
        while (curr && --k) {
            curr = curr->next;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2 || !head || !head->next) 
            return head;

        Node dummy(0);
        dummy.next = head;

        Node* group_prev = &dummy;

        while (true) {
            Node* kth = _get_kth(group_prev->next, k);
            if (!kth) break;

            Node* group_next = kth->next;
            Node* old_start = group_prev->next;
            group_prev->next = _reverse(old_start, group_next);
            group_prev = old_start;
        }

        return dummy.next;
    }
};
