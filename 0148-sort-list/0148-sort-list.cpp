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
 
enum class METHOD {STL, MERGE};
constexpr auto ALGO = METHOD::STL;

ostream& operator<<(ostream& o, const std::vector<ListNode*>& v) {
    for (const auto& e : v) {
        o << e->val << " ";
    }
    o << endl;
    return o;
}

class Solution {
    size_t get_size(ListNode* head) {
        size_t result {};
        while(head) {
            ++result;
            head = head->next;
        }
        return result;
    }
public:
    ListNode* sortListSTL(ListNode* head) {
        if (!head || !head->next) return head;
        auto size = get_size(head);
        std::vector<int> vals(size, 0);

        ListNode* it = head;
        for (size_t i = 0; i < size; ++i) {
            vals[i] = it->val;
            it = it->next;
        }

        std::sort(vals.begin(), vals.end());
        
        it=head;
        for (int i = 0; i < size; ++i) {
            it->val = vals[i];
            it = it->next;
        }
        return head;
    }

    ListNode* sortListMerge(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0, head);
        auto total_size = get_size(head);

        for (size_t size = 1; size < total_size; size <<= 1) {
            ListNode* tail = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                ListNode* left        = curr;
                ListNode* right       = split(left, size);
                curr                  = split(right, size);
                auto [m_head, m_tail] = merge(left, right);
                tail->next            = m_head;
                tail                  = m_tail;
            }
        }
        return dummy.next;
    }

    ListNode* split(ListNode* head, size_t size) {
        for (int i = 1; head && i < size; ++i) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }

    std::pair<ListNode*, ListNode*> merge(ListNode* left, ListNode* right) {
        ListNode dummy(0); 
        ListNode* p = &dummy;
        while(left && right) {
            if (left->val < right->val) {p->next = left;  left  =  left->next;}
            else                        {p->next = right; right = right->next;}
            p = p->next;
        }
        p->next = left ? left : right;
        while (p->next) p = p->next; // move p to tail
        return {dummy.next, p};
    }

    ListNode* sortList(ListNode* head) {
        if constexpr(ALGO == METHOD::STL)
            return sortListSTL(head);
        else if constexpr(ALGO == METHOD::MERGE)
            return sortListMerge(head);
        else
            return head; // default case
    }
};