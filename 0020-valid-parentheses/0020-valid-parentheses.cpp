class Solution {
    static const std::unordered_map<char, char> _map;
    static const std::string open_brackets;
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c: s) {
            if (open_brackets.find(c) != string::npos) { // open bracket
                stack.push(c);
            }
            else { //close bracket
                if (stack.empty() || (stack.top() != _map.at(c)))
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};


const std::unordered_map<char, char> Solution::_map = {{ ')', '(' }, { '}', '{' }, { ']', '[' }};
const std::string Solution::open_brackets = "{([";