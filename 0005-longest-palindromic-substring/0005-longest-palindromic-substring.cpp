class Solution {
    std::pair<int, int> expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return {l + 1, r - l - 1}; // start, length
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < s.size(); ++i) {
            auto [l1, len1] = expand(s, i, i);     // odd
            auto [l2, len2] = expand(s, i, i + 1); // even

            if (len1 > max_len) {
                max_len = len1;
                start = l1;
            }
            if (len2 > max_len) {
                max_len = len2;
                start = l2;
            }
        }
        return s.substr(start, max_len);
    }
};
