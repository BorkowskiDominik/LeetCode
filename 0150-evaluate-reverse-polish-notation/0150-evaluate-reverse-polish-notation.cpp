
template <typename T>
std::map<char, std::function<T(T, T)>> operations_map {
    {'*', std::multiplies<>{}},
    {'/', std::divides<>{}},
    {'+', std::plus<>{}}, 
    {'-', std::minus<>{}}
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> _stack;
        const auto& ops = operations_map<int>;

        for (const auto& token : tokens) {
            if (token.size() == 1 && ops.contains(token[0])) {
                // handle operation
                int a = _stack.top(); _stack.pop();
                int b = _stack.top(); _stack.pop();
                int result = ops.at(token[0])(b, a);
                _stack.push(result);
            } else {
                // handle number
                _stack.push(std::stoi(token));
            }
        }
        return _stack.top();
    }
};