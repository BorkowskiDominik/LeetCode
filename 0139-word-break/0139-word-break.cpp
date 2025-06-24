enum class ALGORITHM {TRIE, DP_ARRAY};
constexpr auto ALGO = ALGORITHM::DP_ARRAY;

struct Trie {
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children;
        bool is_word = false;
        Node* operator[](char c) {
            int idx = c - 'a';
            if (!children[idx])
                children[idx] = std::make_unique<Node>();
            return children[idx].get();
        }

        Node* at(char c) {
            return children[c-'a'].get();
        }
    };
    std::unique_ptr<Node> _head;

    Trie(): _head(std::make_unique<Node>()) {}

    void insert(const std::string_view& s) {
        Node* n = _head.get();
        for (auto c: s) {
            n = (*n)[c];
        }
        n->is_word = true;
    }

    bool isPrefix(char c) const {
        return _head->at(c);
    }

    bool isPrefix(const std::string_view& s) const {
        Node* n = _head.get();
        for (auto c: s) { 
            n = n->at(c);
            if (!n) return false;
        }
        return true;
    }

    bool isWord(const std::string_view& s) const {
        Node* n = _head.get();
        for (auto c: s) { 
            n = n->at(c);
            if (!n) return false;
        }
        return n->is_word;
    }
};

class Solution {
    bool canConstruct(const string_view& view, const Trie& trie, const size_t start,  std::vector<int8_t>& cache) const {
        if (cache[start] != -1) return cache[start];
        int8_t result = 0;
        string_view s = view.substr(start, view.size()-start);
        if (s == "" || trie.isWord(s)) {
            result = 1;
        } else if (trie.isPrefix(s.front())) {
            for (size_t i = 1; i < s.size(); ++i) {
                if (trie.isWord(s.substr(0, i)))
                    if (canConstruct( view, trie, start + i, cache ))
                        result =  1;
            }
        }
        cache[start] = result;
        return cache[start];
    }

    bool _wordBreakTrie(const string& s, vector<string>& wordDict) const {
        Trie trie;
        for_each(wordDict.begin(), wordDict.end(), [&trie](const auto& s){trie.insert(s);});
        std::vector<int8_t> cache(s.size(), -1);
        return canConstruct(s, trie, 0, cache);
    }

    bool _wordBreakDpArray(const std::string& s, vector<string>& wordDict) const {
        int n = s.size();

        unordered_set<string_view> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <=n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j])
                    continue;
                auto sv = string_view(s).substr(j, i-j);
                if (dict.count(sv)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

public:
    bool wordBreak(const string& s, vector<string>& wordDict) const {
        if constexpr(ALGO == ALGORITHM::TRIE) {
            return _wordBreakTrie(s, wordDict); // Result: Runtime: 60% - 100% (Most often: 75%), Memory: 61%
        } else if constexpr(ALGO == ALGORITHM::DP_ARRAY) {
            return _wordBreakDpArray(s, wordDict); // Result: Runtime: 70%-100% (Most often: 100%), Memory: 90.04%
        }
        return false;
    }
};