/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        std::queue<Node*> _queue; 
        _queue.push(root);
        while(!_queue.empty()) {
            int level_size = _queue.size();
            for ( int i = 0; i < level_size; ++i) {
                auto current = _queue.front(); _queue.pop();
                auto n = _queue.front();
                current->next = (i != level_size -1) ? n  : nullptr;
                if (current->left) _queue.push(current->left);
                if (current->right) _queue.push(current->right);
            }
        }
        return root;
    }
};