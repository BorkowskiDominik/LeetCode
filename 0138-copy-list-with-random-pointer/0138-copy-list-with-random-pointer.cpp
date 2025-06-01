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
    Node* copyRandomList(Node* head) {
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
            copy_tail->next = mapping[org_tail->next];
            copy_tail->random = mapping[org_tail->random];
            org_tail = org_tail->next;
            copy_tail = copy_tail->next;
        }

        return copy_head->next;
    }
};