
class Trie {
public:
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool is_terminal = false;
        Node* get(char c) { return children[c-'a'].get(); }
        void remove(char c) { children[c-'a'] = nullptr; }
    };

private:
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

    Node* get_node(char c) {
        return head->get(c);
    }
};

struct Point {
    int x;
    int y;
    bool operator==(const Point&) const = default;
};

namespace std {
    template<>
    struct hash<Point> {
        std::size_t operator()(const Point& s) const noexcept {
            return std::hash<int>{}(s.x) ^ (std::hash<int>{}(s.y) << 1);
        }
    };
}

class Solution {
    static constexpr int MAX_WORD_LEN = 10;
    static constexpr std::array<Point, 4> DIRECTIONS = {{{-1, 0},{1, 0},{0, 1},{0, -1}}};
private: 
    Trie generate_trie(const vector<string>& words) {
        Trie trie {};
        for (const auto& word : words)
            trie.insert(word);
        return trie;
    }

    inline bool check_point(const vector<vector<char>>& board, const Point& p) const {
        return p.x >= 0 && p.y >= 0 && p.x < board.size() && p.y < board[0].size();
    }

    inline bool should_prune(Trie::Node* n) {
        if (n->is_terminal) return false;
        return std::all_of(n->children.begin(), n->children.end(), [](const auto& ptr){ return !ptr;});
    }

    void dfs(const vector<vector<char>>& board,
            std::unordered_set<Point>& visited,
            std::string& current_word,
            const Point& pos,
            Trie::Node* n,
            std::vector<string>& solutions) {
        if (!n) return;
        if (n->is_terminal) {
            solutions.push_back(current_word);
            n->is_terminal = false; // to avoid duplicates
        };
        if (current_word.size() == MAX_WORD_LEN) return;
        for (const auto& dir : DIRECTIONS) {
            Point next {pos.x + dir.x, pos.y + dir.y};
            if (!check_point(board, next) || visited.contains(next)) continue;
            visited.insert(next);
            char c = board[next.x][next.y];
            current_word.push_back(c);
            dfs(board, visited, current_word, next, n->get(c), solutions);
            // if (should_prune(n))
                // n->remove(c);
            current_word.pop_back();
            visited.erase(next);
        }
    }

    vector<string> find_words(const vector<vector<char>>& board, Trie& trie) {
        string current_word;
        std::unordered_set<Point> visited;
        std::vector<string> solutions;

        current_word.reserve(MAX_WORD_LEN);
        visited.reserve(MAX_WORD_LEN);
        
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                char c = board[row][col];
                Trie::Node* n = trie.get_node(c);
                if (!n) continue;
                Point p {row, col};
                visited.insert(p);
                current_word.push_back(c);
                dfs(board, visited, current_word, p, n, solutions);
                current_word.pop_back();
                visited.clear();
            }
        }
        return solutions;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = generate_trie(words);
        return find_words(board, trie);
    }
};
