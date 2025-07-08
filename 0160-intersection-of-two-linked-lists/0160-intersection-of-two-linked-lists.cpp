/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // very interesting solution
    // if one pointer reaches the end we move it to other path,
    // and the same thing we do with second pointer.
    // because of it after 1 such cycle each will do the same number of 
    // steps ( lenA + lenB) and they will meet and common node (or the end)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) const {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }

    // my solution, not very memory efficient
    // I think it would be better just to iterate over single path (A or B)
    // and then start iterating through other one and check if node is visied
    ListNode *getIntersectionNodeMY(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        
        std::unordered_set<ListNode*> visited;
        while (headA || headB) {
            if (headA) {
                if (visited.contains(headA)) 
                    return headA;
                visited.insert(headA);
                headA = headA->next;
            }
            if (headB) {
                if (visited.contains(headB))
                    return headB;
                visited.insert(headB);
                headB = headB->next;
            }
        }

        return nullptr;
    }
};