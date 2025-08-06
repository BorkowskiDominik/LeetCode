constexpr std::array<char, 26> buildKeyboardMap() {
    std::array<char, 26> map{}; // 0 = no row, 1 = row 1, 2 = row 2, 3 = row 3
    for (char c : std::string_view("qwertyuiop")) map[c - 'a'] = 1;
    for (char c : std::string_view("asdfghjkl")) map[c - 'a'] = 2;
    for (char c : std::string_view("zxcvbnm")) map[c - 'a'] = 3;
    return map;
}

constexpr std::array<char, 26> KEYBOARD_MAP = buildKeyboardMap();

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        result.reserve(words.size());
        for (const auto& word : words) {
            if (word.empty()) continue;
            char row = KEYBOARD_MAP[std::tolower(word.front()) - 'a'];
            if (row == 0) continue; // Invalid letter (shouldn't happen)
            if (std::all_of(word.begin(), word.end(), [row](char c) {
                    return KEYBOARD_MAP[std::tolower(c) - 'a'] == row;
                })) {
                result.push_back(word);
            }
        }
        return result;
    }
};