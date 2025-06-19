enum class METHOD {
    RECURSIVE,
    ITERATIVE
};
constexpr METHOD ALGO = METHOD::ITERATIVE;

const static unordered_map<char, std::vector<char>> button_to_letters {
    {'1', {}},
    {'2',{'a', 'b', 'c'}},
    {'3',{'d', 'e', 'f'}},
    {'4',{'g', 'h', 'i'}},
    {'5',{'j', 'k', 'l'}},
    {'6',{'m', 'n', 'o'}},
    {'7',{'p', 'q', 'r', 's'}},
    {'8',{'t', 'u', 'v'}},
    {'9',{'w', 'x', 'y', 'z'}},
    {'0', {}}
};


class Solution {
public:
    void build_word(string& word, const string& digits, std::vector<std::string>& result) {
        if (digits.empty()){
            result.push_back(word);
        }

        for (char l : button_to_letters.at(digits.front())) {
            word.push_back(l);
            build_word(word, digits.substr(1, digits.size()-1), result);
            word.pop_back();
        }
    }

    vector<string> letterCombinationsRecursive(string digits) {
        std::vector<std::string> result;
        std::string word;
        word.reserve(digits.size());
        build_word(word, digits, result);
        return result;
    }

    vector<string> letterCombinationsIterative(string digits) {
        if (digits.empty()) return {};

        vector<string> result = {""};

        for (char digit : digits) {
            vector<string> temp;
            for (const string& prefix : result) {
                for (char letter : button_to_letters.at(digit)) {
                    temp.push_back(prefix + letter);
                }
            }
            result = std::move(temp);
        }

        return result;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        if constexpr(ALGO == METHOD::ITERATIVE) {
            return letterCombinationsIterative(digits);
        } else if constexpr(ALGO == METHOD::RECURSIVE) {
            return letterCombinationsRecursive(digits);
        } else {
            return {}; // return empty vector, algorithm not selected
        }
    }
};