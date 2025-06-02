class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int _capacity;
    unordered_map<int, Node*> _mapping;
    Node *head, *tail;

    void _move_to_top(Node* n) {
        if (head == n) return;

        // Unlink n from its current position
        if (n->prev) n->prev->next = n->next;
        if (n->next) n->next->prev = n->prev;

        if (tail == n) tail = n->prev;

        // Move n to the front
        n->prev = nullptr;
        n->next = head;
        if (head) head->prev = n;
        head = n;

        if (!tail) tail = n;
    }

public:
    LRUCache(int capacity) : _capacity(capacity), head(nullptr), tail(nullptr) {
        _mapping.reserve(capacity);
    }

    int get(int key) {
        auto it = _mapping.find(key);
        if (it == _mapping.end()) return -1;
        Node* n = it->second;
        _move_to_top(n);
        return n->val;
    }

    void put(int key, int value) {
        Node* n;
        auto it = _mapping.find(key);

        if (it != _mapping.end()) {
            // Key exists, update and move to top
            n = it->second;
            n->val = value;
        } else {
            if (_mapping.size() == _capacity) {
                // Reuse tail node
                n = tail;
                _mapping.erase(tail->key);

                // Unlink tail
                if (tail->prev) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    head = tail = nullptr;
                }

                n->key = key;
                n->val = value;
                n->prev = n->next = nullptr;
            } else {
                // Create new node
                n = new Node(key, value);
            }
            _mapping[key] = n;
        }

        _move_to_top(n);
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
