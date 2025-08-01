class Solution {
public:
    int firstUniqChar(string s) {
        std::array<int, 26> used {}; // letters counter
        for (char l : s) {
            used[l-'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (used[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};