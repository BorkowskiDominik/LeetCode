class Solution {
public:
    char findTheDifference(string_view s, string_view t) {
        char r = '\0';
        for (auto l: s)
            r ^= l;
        for (auto l: t)
            r ^= l;
        return r;
    }
};