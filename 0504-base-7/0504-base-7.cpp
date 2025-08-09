class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string out;
        bool negative = 0;
        if (num < 0) {
            num = -num;
            negative = true;
        }

        while (num) {
            out += to_string(num%7);
            num /= 7;
        }

        if (negative)
            out.push_back('-');
        std::reverse(out.begin(), out.end());
        return out;
    }
};