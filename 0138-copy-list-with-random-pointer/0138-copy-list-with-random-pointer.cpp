/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    // hashing solution Runtime: O(n), Memory: O(n)
    Node* copyRandomListHashing(Node* head) {
        unordered_map<Node*, Node*> mapping;
        mapping[NULL] = NULL;
        Node* org_head = head;
        Node* org_tail = head;
        
        Node dummy(0);
        Node* copy_head = &dummy;
        Node* copy_tail = copy_head;

        while(org_tail)
        {
            Node* new_node = new Node(org_tail->val);
            mapping[org_tail] = new_node;
            copy_tail->next = new_node;
            org_tail = org_tail->next;
            copy_tail = copy_tail->next;
        }
        org_tail = org_head;
        copy_tail = copy_head->next;

        while(copy_tail)
        {
            // copy_tail->next = mapping[org_tail->next];
            copy_tail->random = mapping[org_tail->random];
            org_tail = org_tail->next;
            copy_tail = copy_tail->next;
        }

        return copy_head->next;
    }

    // inserting copies after originals and then splitting it back
    // Runtime: O(n) Memory: O(1)
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert new nodes just after orginal
        Node* curr = head;
        while (curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }

        // 2. Set random pointers (at this point copy is next element after original one)
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Separate old and new list
        Node* new_head = head->next;
        Node* orig = head;
        Node* copy = new_head;

        while (orig) {
            orig->next = copy->next;
            orig = orig->next;
            if (orig) {
                copy->next = orig->next;
                copy = copy->next;
            }
        }

        return new_head;
    }
};