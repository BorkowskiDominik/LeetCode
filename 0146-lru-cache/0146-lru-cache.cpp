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
        if (tail == n) tail = n->prev;
        if (n->prev) n->prev->next = n->next;
        if (n->next) n->next->prev = n->prev;

        n->next = head;
        if(head) head->prev = n;
        n->prev = nullptr;
        head = n;

        if(!tail) tail = head;
    }

public:
    LRUCache(int capacity): head(nullptr), tail(nullptr), _capacity(capacity) {
        _mapping.reserve(capacity);
    }
    
    int get(int key) {
        if(!_mapping.contains(key))
            return -1;
        auto node = _mapping[key];
        _move_to_top(node);
        return node->val;
    }
    
    void put(int key, int value) {
        Node *n;
        auto it = _mapping.find(key);
        if(it != _mapping.end()) {
            it->second->val = value;
            n = it->second;
        } else {
            if(_mapping.size() == _capacity) {
                cout << "key: " << key << " : " << value << endl;
                auto node = _mapping.extract(tail->key);
                node.key() = key;
                n = node.mapped();
                n->key = key;
                n->val = value;
                _mapping.insert(std::move(node));
            }
            else {
                n = new Node(key, value);
                _mapping[key] = n;
                if(!head && !tail)  {
                    head = tail = n; 
                }
            }
        }        
        _move_to_top(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */