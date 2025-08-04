class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        if (std::islower(word.at(0)) || std::islower(word.at(1)))
            return std::all_of(
                word.begin()+1,
                word.end(),
                [](unsigned char c) { return std::islower(c); }
            );
        return std::all_of(
            word.begin(),
            word.end(),
            [](unsigned char c) { return std::isupper(c); }
        );
    }
};