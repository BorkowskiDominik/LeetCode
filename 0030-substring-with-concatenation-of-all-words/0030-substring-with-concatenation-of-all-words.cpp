// Solved using sliding window technique

class Solution {
    std::unordered_map<std::string, int> get_word_counter(vector<string>& words) {
        std::unordered_map<std::string, int> result;
        for (const auto&w : words)
            result[w]++;
        return result;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) return {};
        std::vector<int> indexes;
        auto word_counter = get_word_counter(words);
        int words_num = words.size();
        int word_len = words.front().size();

        for (int offset = 0; offset < word_len; ++offset) {
            int left = offset;
            int right = offset;
            decltype(word_counter) window_count;
            int words_used = 0;
            
            while (right + word_len <= s.length()) {
                string word = s.substr(right, word_len);
                right += word_len;

                if (word_counter.contains(word)) {
                    ++window_count[word];
                    ++words_used;
                    
                    while (window_count[word] > word_counter[word]) {
                        string left_word = s.substr(left, word_len);
                        --window_count[left_word];
                        --words_used;
                        left += word_len;
                    }

                    if (words_used == words_num)
                        indexes.push_back(left);

                } else { // word does not match - reset window
                    window_count.clear();
                    words_used = 0;
                    left = right;
                }
            }
        }
        return indexes;
    }
};
