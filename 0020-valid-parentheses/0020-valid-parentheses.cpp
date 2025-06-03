class Solution {
    inline static const std::unordered_map<char, char> close_to_open = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty() || stack.top() != close_to_open.at(c))
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
