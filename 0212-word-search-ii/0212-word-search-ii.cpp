class Trie {
public:
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool is_terminal = false;
        inline Node* get(char c) { return children[c-'a'].get(); }
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
    
    [[maybe_unused]]
    bool search(const string& word) const {
        Node* n = head.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!n->children[idx]) return false;
            n = n->children[idx].get();
        }
        return n->is_terminal;
    }
    
    [[maybe_unused]]
    bool startsWith(const string& prefix) const {        
        Node* n = head.get();
        for (char c : prefix) {
            int idx = c - 'a';
            if (!n->children[idx]) return false;
            n = n->children[idx].get();
        }
        return true;
    }

    inline Node* get_node(char c) {
        return head->get(c);
    }
};


struct Point {
    int x;
    int y;
    bool operator==(const Point&) const = default;
};

#if 0
namespace std {
    template<>
    struct [[deprecated("Created for set purposed - no needed anymore")]] hash<Point> {
        std::size_t operator()(const Point& s) const noexcept {
            return std::hash<int>{}(s.x) ^ (std::hash<int>{}(s.y) << 1);
        }
    };
}
#endif

class Solution {
    static constexpr int MAX_WORD_LEN = 10;
    static constexpr std::array<Point, 4> DIRECTIONS = {{{-1, 0},{1, 0},{0, 1},{0, -1}}};
    
    template<typename T>
    using TV = vector<T>;

    template<typename T>
    using TVV = vector<vector<T>>;

    Trie generate_trie(const TV<string>& words) {
        Trie trie {};
        for (const auto& word : words)
            trie.insert(word);
        return trie;
    }

    inline bool check_point(const TVV<char>& board, const Point& p) const {
        return p.x >= 0 && p.y >= 0 && p.x < board.size() && p.y < board[0].size();
    }

    inline bool should_prune(Trie::Node* n) {
        if (!n) 
            return true;
        if (n->is_terminal) 
            return false;
        return std::none_of(n->children.begin(), n->children.end(), 
                    [](const auto& ptr){ return static_cast<bool>(ptr);}
                );
    }

    void dfs(const TVV<char>& board,
            const Point& pos,
            TVV<bool>& visited,
            std::string& current_word,
            Trie::Node* n,
            TV<string>& solutions) {
        if (!n)
            return;
        
        if (n->is_terminal) {
            solutions.push_back(current_word);
            n->is_terminal = false; // to avoid duplicates
        };
        
        if (current_word.size() == MAX_WORD_LEN) 
            return;
        
        for (const auto& dir : DIRECTIONS) {
            Point next {pos.x + dir.x, pos.y + dir.y};
            
            if (!check_point(board, next) || visited[next.x][next.y]) 
                continue;
            
            char c = board[next.x][next.y];
            Trie::Node* child = n->get(c);
            if (!child)
                continue;

            visited[next.x][next.y] = true;
            current_word.push_back(c);            
            dfs(board, next, visited, current_word, child, solutions);
            if (should_prune(child))
                n->remove(c);
            current_word.pop_back();
            visited[next.x][next.y] = false;
        }
    }

    TV<string> find_words(const TVV<char>& board, Trie& trie) {
        string current_word;
        // std::unordered_set<Point> visited; 
        // using const size vector of bools helped to dramatically reduce execution time
        // compared to unoredered_set, because no reallocations where needed neighter any
        // kind of inserions and deletions
        TVV<bool> visited(board.size(), TV<bool>(board[0].size(), false));
        TV<string> solutions;

        current_word.reserve(MAX_WORD_LEN);
        
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                char c = board[row][col];
                Trie::Node* n = trie.get_node(c);
                if (!n)
                    continue;
                Point p {row, col};
                visited[p.x][p.y] = true;
                current_word.push_back(c);
                
                dfs(board, p, visited, current_word, n, solutions);
                
                current_word.pop_back();
                visited[p.x][p.y] = false;
            }
        }
        return solutions;
    }

public:
    TV<string> findWords(TVV<char>& board, TV<string>& words) {
        Trie trie = generate_trie(words);
        return find_words(board, trie);
    }
};
