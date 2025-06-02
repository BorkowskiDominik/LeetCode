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
struct List {
    ListNode* head;
    ListNode* tail;
    List() : head(nullptr), tail(nullptr) {}
    void operator+=(ListNode* new_node) {
        if (!head) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        tail->next = nullptr;
    }
};

ostream& operator<<(ostream& o, const List& list) {
    ListNode* h = list.head;
    while(h) {
        o << h->val << " ";
        h = h->next;
    }
    o << endl;
    return o;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        List less, greater_eq;
        ListNode* next = nullptr;
        while(head) {
            next = head->next;
            int val = head->val;
            if (val < x) {
                less += head;
            }
            else {
                greater_eq += head;
            }
            head = next;
        }
        // cout << "less:" << less;
        // cout << "more:" << greater_eq;
        if (less.tail) {
            head = less.head;
            less.tail->next = greater_eq.head;
        }
        else
            head = greater_eq.head;
        return head;
    }
};
