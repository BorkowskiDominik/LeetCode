class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t fg = haystack.find(needle);
        return (fg==string::npos) ? -1 : static_cast<int>(fg);
    }
};