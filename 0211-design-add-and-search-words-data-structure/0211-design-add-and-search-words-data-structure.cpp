// Extended Trie from task 208
class WordDictionary {
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool is_terminal;
    };
    std::unique_ptr<Node> head;
public:
    WordDictionary(): head(std::make_unique<Node>()) {}
    
    void addWord(const string& word) {
        Node* n = head.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!n->children[idx])
                n->children[idx] = std::make_unique<Node>();
            n = n->children[idx].get();
        }
        n->is_terminal = true;
    }

    bool _search_from(const string& word, int pos, Node* n) const {
        if (!n) return false;
        if (pos == word.size()) return n->is_terminal;

        char c = word[pos];
        if (c != '.') {
            int idx = c - 'a';
            return _search_from(word, pos + 1, n->children[idx].get());
        } else {
            for (const auto& child : n->children) {
                if (child && _search_from(word, pos + 1, child.get()))
                    return true;
            }
        }
        return false;
    }

    bool search(const string& word) const {
        return _search_from(word, 0, head.get());
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
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */