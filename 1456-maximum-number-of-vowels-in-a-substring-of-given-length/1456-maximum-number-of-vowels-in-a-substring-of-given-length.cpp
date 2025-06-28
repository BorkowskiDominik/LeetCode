class Solution {
    static constexpr std::array<bool, 256> VOWELS = []{
        std::array<bool, 256> table{};
        table['a'] = table['e'] = table['i'] = table['o'] = table['u'] = true;
        return table;
    }();

public:
    int maxVowels(std::string_view s, int k) {
        auto vowels = std::count_if(s.begin(), s.begin()+k, [this](char c){return VOWELS[c];});
        auto maxVowels = vowels;
        for (int i = k; i < s.size(); ++i) {
            if (VOWELS[s[i]]) ++vowels;
            if (VOWELS[s[i-k]]) --vowels;
            maxVowels = std::max(maxVowels, vowels);
            if (maxVowels == k) break;
        }
        return maxVowels;
    }
};
