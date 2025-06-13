class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        std::vector<int> stack;
        int i = 0;
        int n = s.size();

        while (i < n) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                result += sign * num;
                continue;  // i already incremented
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                stack.push_back(result);
                stack.push_back(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                int prev_sign = stack.back(); stack.pop_back();
                int prev_result = stack.back(); stack.pop_back();
                result = prev_result + prev_sign * result;
            }
            ++i;  // przeskocz operator/spację/nawias
        }

        return result;
    }

    int calculate_with_string_stream(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {return c== ' ';}), s.end());
        int result {};
        std::stack<int> context{};
        context.push(1);
        istringstream iss{s};

        int last_sign = 1;
        while(iss.peek() != EOF) {
            char c = iss.peek();
            switch (c) {
                case '(':
                    context.push(context.top() * last_sign);
                    last_sign = 1;
                    iss.get();
                    break;
                case ')':
                    context.pop();
                    iss.get();
                    break;
                case '+':
                    last_sign = 1;
                    iss.get();
                    break;
                case '-':
                    last_sign = -1;
                    iss.get();
                    break;
                default:
                    int i;
                    if (iss >> i)
                        result += last_sign*context.top()*i;
            }
        }
        return result;
    }
};