constexpr bool ON_THE_FLY = true;
constexpr int NO_SOLUTION = 0;


class Solution {
    using TGraph = unordered_map<const string*, unordered_set<const string*>>;
    inline const int get_diffs(const string& s1, const string&s2) const {
        int diffs {};
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) ++diffs;
            if (diffs > 1) return diffs;
        }
        return diffs;
    }

    [[maybe_unused]]
    int find_distance(const string& s1, const string& s2, const vector<string>& wordList) {
        std::queue<const string*> bfs_queue;
        std::unordered_set<const string*> visited;
        bfs_queue.push(&s1);
        int path_len {1};

        while(!bfs_queue.empty()) {
            int level_size = bfs_queue.size();
            ++path_len;
            for (int i = 0; i < level_size; ++i) {
                auto el = bfs_queue.front(); bfs_queue.pop();
                for (const auto& word : wordList) {
                    if (!visited.contains(&word) && get_diffs(word, *el) == 1) {
                        if (word == s2)
                            return path_len;
                        bfs_queue.push(&word);
                        visited.insert(&word);
                    }
                }
            }
        }
        return NO_SOLUTION;
    }

    [[maybe_unused]]
    int find_distance_graph(const string& s1, const string& s2, const TGraph& graph) {
        std::queue<const string*> bfs_queue;
        std::unordered_set<const string*> visited;
        auto it = std::find_if(graph.begin(), graph.end(), [&s1](const auto& p){ return *(p.first) == s1;});
        if (it == graph.end()) return NO_SOLUTION;
        bfs_queue.push(it->first);
        int path_len {1};

        while(!bfs_queue.empty()) {
            int level_size = bfs_queue.size();
            ++path_len;
            for (int i = 0; i < level_size; ++i) {
                auto el = bfs_queue.front(); bfs_queue.pop();
                for (const auto& word : graph.at(el)) {
                    if (!visited.contains(word) && get_diffs(*word, *el) == 1) {
                        if (*word == s2)
                            return path_len;
                        bfs_queue.push(word);
                        visited.insert(word);
                    }
                }
            }
        }
        return NO_SOLUTION;
    }

    int ladderLength_on_fly(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front(); q.pop();
                if (word == endWord) return steps;

                for (int i = 0; i < word.size(); ++i) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        word[i] = c;
                        if (dict.count(word)) {
                            q.push(word);
                            dict.erase(word); // mark as visited
                        }
                    }
                    word[i] = orig;
                }
            }
            ++steps;
        }

        return NO_SOLUTION;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if constexpr(ON_THE_FLY) {
            return ladderLength_on_fly(beginWord, endWord, wordList);
        } else {
            if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return NO_SOLUTION;
            return find_distance(beginWord, endWord, wordList);
        }
    }
};