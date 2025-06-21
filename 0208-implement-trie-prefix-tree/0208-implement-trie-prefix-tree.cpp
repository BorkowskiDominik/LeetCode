class Trie {
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool is_terminal;
    };
    std::unique_ptr<Node> head;
public:
    Trie(): head(std::make_unique<Node>()) {}
    
    void insert(const string& word) {
        Node* n = head.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!n->children[idx])
                n->children[idx] = std::make_unique<Node>();
            n = n->children[idx].get();
        }
        n->is_terminal = true;
    }
    
    bool search(const string& word) const {
        Node* n = head.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!n->children[idx]) return false;
            n = n->children[idx].get();
        }
        return n->is_terminal;
    }
    
    bool startsWith(const string& prefix) const {        
        Node* n = head.get();
        for (char c : prefix) {
            int idx = c - 'a';
            if (!n->children[idx]) return false;
            n = n->children[idx].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */