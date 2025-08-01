class Solution {
public:
    string addStrings(string num1, string num2) {
        const int n1 = num1.size();
        const int n2 = num2.size();

        auto maxLen = std::max(n1, n2);
        string result;
        result.reserve(maxLen + 1);
        int remainder = 0;

        for (int i = 0; i < maxLen; ++i) {
            auto sum = remainder;
            if (i < n1)
                sum += num1[n1-1-i] - '0';
            if (i < n2)
                sum += num2[n2-1-i] - '0';
            remainder = sum / 10;
            result.push_back((sum % 10)+'0');
        }
        if (remainder)
            result.push_back('1');
        return string(result.rbegin(), result.rend());
    }
};