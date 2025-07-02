class Solution {
    [[maybe_unused]]
    string repeat_str(int n, std::string& s) { // ver 1
        std::string result;
        result.reserve(n * s.size());
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }

    void append_repeated_n(int n, std::string& dest,  std::string& s) { // ver 2
        int space_required = n * s.size();
        int free_to_use = dest.capacity() - dest.size();
        if (space_required > free_to_use)
            dest.reserve(space_required - free_to_use);

        for (int i = 0; i < n; ++i) {
            dest += s;
        }
    }

public:
    string decodeString(string_view s) {
        std::string result;
        std::stack<std::pair<int, std::string>> _stack;
        _stack.emplace(1, result);

        std::string number;
        number.reserve(3);
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                number.push_back(c);
            } else if (c == '[') {
                int rep = stoi(number);
                _stack.emplace(rep, "");
                number.clear();
            } else if (c == ']') {
                auto [rep, s] = _stack.top(); _stack.pop();
                //_stack.top().second += repeat_str(rep, s); // ver1
                append_repeated_n(rep, _stack.top().second, s); // ver2
            } else {
                _stack.top().second.push_back(c);
            }
        }

        return _stack.top().second;
    }
};