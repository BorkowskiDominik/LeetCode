class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 
                                    'A', 'E', 'I', 'O', 'U'};
        auto is_vowel = [&vowels](char c) { return vowels.contains(c); };

        auto it_f = std::find_if(s.begin(), s.end(), is_vowel);
        auto it_e = std::find_if(s.rbegin(), s.rend(), is_vowel);

        while (it_f < it_e.base() - 1) {
            std::iter_swap(it_f, it_e);
            it_f = std::find_if(std::next(it_f), s.end(), is_vowel);
            it_e = std::find_if(std::next(it_e), s.rend(), is_vowel);
        }

        return s;
    }
};