class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::array<std::string, 256> _l_to_word; // letter to word mapping
        std::unordered_map<std::string, int> _word_to_l;

        istringstream is(s);
        string word;

        for (char c : pattern) {
            if(is.eof())
                return false;
            is >> word;
            if ( !_l_to_word[c].empty() && _l_to_word[c] != word )
                return false;
            auto it = _word_to_l.find(word);
            if (it != _word_to_l.end() && it->second != c)
                return false;
            _l_to_word[c] = word;
            _word_to_l[word] = c;
        }
        return is.eof();
    }
};