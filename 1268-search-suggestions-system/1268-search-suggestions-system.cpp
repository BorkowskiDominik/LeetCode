constexpr int NO_OF_SUGGESTIONS = 3;

class Trie {
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool isWord = false;
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
        n->isWord = true;
    }
    
    bool search(const string& word) const {
        Node* n = head.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!n->children[idx]) return false;
            n = n->children[idx].get();
        }
        return n->isWord;
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

    void dfs(Node* node, std::string& word, std::vector<std::string>& results, int n) const {
        if (!node || results.size() == n) return;
        
        if (node->isWord) {
            results.push_back(word);
            if (results.size() == n) return;
        }

        for (int i = 0; i < node->children.size(); ++i) {
            if (!node->children[i]) continue;
            word.push_back('a' + i);
            dfs(node->children[i].get(), word, results, n);
            word.pop_back();
        }
    }

    std::vector<std::string> getSuggestions(const std::string_view& prefix, int n) const {
        std::vector<std::string> suggestions;
        suggestions.reserve(n);
        std::string word {prefix};

        Node* node = head.get();
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return suggestions;
            node = node->children[idx].get();
        }
        dfs(node, word, suggestions, n);
        return suggestions;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> results;
        results.reserve(searchWord.size());

        Trie trie;
        for (const auto& product : products) {
            trie.insert(product);
        }

        for (int i = 1; i <= searchWord.size(); ++i) {
            std::string_view prefix = std::string_view(searchWord).substr(0, i);
            results.push_back(trie.getSuggestions(prefix, NO_OF_SUGGESTIONS));
        }

        return results;
    }
};

