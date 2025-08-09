class Solution {
public:
    string reverseWords(string s) {
        for (auto it = s.begin(); it < s.end(); ) {
            auto word_end = std::find(it, s.end(), ' ');
            std::reverse(it, word_end);
            if (word_end == s.end())
                break;
            it = std::next(word_end);
        }
        return s;
    }
};