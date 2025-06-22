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
    ListNode* _mergeSort(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while(lists.size() > 1) {
            auto it_left = lists.begin();
            auto it_right = lists.end()-1;
            while (it_left < it_right) {
                *it_left = _mergeSort(*it_left, *it_right);
                ++it_left; 
                --it_right;
                lists.pop_back();
            }
        }
        return lists.front();
    }
};