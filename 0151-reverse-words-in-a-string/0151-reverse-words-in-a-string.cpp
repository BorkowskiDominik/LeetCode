class Solution {
public:
    std::string reverseWords(std::string s) {
        // 1. Usuń nadmiarowe spacje
        trimSpaces(s);

        // 2. Odwróć cały string
        std::reverse(s.begin(), s.end());

        // 3. Odwróć każde słowo osobno
        int n = s.size();
        int start = 0;
        for (int end = 0; end <= n; ++end) {
            if (end == n || s[end] == ' ') {
                std::reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }

private:
    void trimSpaces(std::string& s) {
        int n = s.size();
        int i = 0, j = 0;
        while (i < n && s[i] == ' ') ++i;  // leading spaces
        while (i < n) {
            if (s[i] != ' ' || (j > 0 && s[j - 1] != ' ')) {
                s[j++] = s[i];
            }
            ++i;
        }
        if (j > 0 && s[j - 1] == ' ') --j; // remove trailing space
        s.resize(j);
    }
};
