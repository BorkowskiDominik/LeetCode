class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::array<std::string, 256> _l_to_word; // letter to word mapping
        std::unordered_map<std::string, int> _word_to_l;

        istringstream is(s);
        string word;

        for (char c : pattern) {
            if(!(is >> word))   return false;

            if (!_l_to_word[c].empty() && _l_to_word[c] != word )  return false;
            if (_word_to_l.contains(word) && _word_to_l[word] != c) return false;

            _l_to_word[c] = word;
            _word_to_l[word] = c;
        }
        string extra;
        return !(is >> extra);
    }
};