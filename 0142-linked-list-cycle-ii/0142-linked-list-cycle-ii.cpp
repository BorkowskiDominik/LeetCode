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
    // optimal
    ListNode* detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!fast || !fast->next)
            return nullptr;

        // iteresting mathematical property
        // if there is an cycle pointer will meet at its beginning
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    ListNode* detectCycle1(ListNode *head) { 
        unordered_set<ListNode*> visited;
        while (head && !visited.contains(head)) {
            visited.insert(head);
            head = head ->next;
        }
        return head;
    }


    // first detect cycle, then build dict, and 
    // start another pointer from head until it
    // points to any of elements in cycle
    ListNode* detectCycle2(ListNode *head) {
        if (!head) return head;
        ListNode* pursuer = head;
        ListNode* fast = head->next;

        for (bool even = false; fast != nullptr && fast != pursuer; even = !even) {
            fast = fast->next;
            if (even)
                pursuer = pursuer->next;
        }
        
        if (fast == nullptr) 
            return nullptr; // there is no cycle

        // build cycle
        unordered_set<ListNode*> cycle;
        cycle.insert(fast);
        fast = fast->next;
        while (fast != pursuer) {
            cycle.insert(fast);
            fast = fast->next;
        }

        // now start new pointer from the head
        pursuer = head;
        while (!cycle.contains(pursuer)) {
            pursuer = pursuer->next;
        }
        return pursuer;
    }
};