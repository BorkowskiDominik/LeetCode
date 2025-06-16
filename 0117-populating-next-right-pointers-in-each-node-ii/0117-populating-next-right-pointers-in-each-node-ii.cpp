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
enum class METHOD: int {
    QUEUE,
    DUMMY_NODE
};

constexpr METHOD ALGORITHM = METHOD::DUMMY_NODE;


class Solution {
public:
    Node* connect(Node* root) { 
        if constexpr(ALGORITHM == METHOD::QUEUE) {
            return connect_queue(root);
        } else if constexpr(ALGORITHM == METHOD::DUMMY_NODE) {
            return connect_dummy(root);
        } else {
            static_assert([](){return false;}, "Select proper execution mode!");
            return root;
        }
    }

    Node* connect_dummy(Node* root) {
        if (!root) return nullptr;
        Node* leftmost = root;

        while (leftmost) {
            Node* dummy = new Node(0);
            Node* tail = dummy;
            Node* curr = leftmost;

            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }

            leftmost = dummy->next;
            delete dummy;
        }

        return root;
    }

    Node* connect_queue(Node* root) {
        if(!root) return root;

        std::queue<Node*> _queue; 
        _queue.push(root);
        while(!_queue.empty()) {
            int level_size = _queue.size();
            for ( int i = 0; i < level_size; ++i) {
                auto current = _queue.front(); _queue.pop();
                if (i < level_size - 1)
                    current->next = _queue.front();
                else
                    current->next = nullptr;
                if (current->left) _queue.push(current->left);
                if (current->right) _queue.push(current->right);
            }
        }
        return root;
    }
};