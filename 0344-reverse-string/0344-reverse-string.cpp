class Solution {
public:
    void reverseString(vector<char>& s) {
        auto s_size = s.size();
        for (int i = 0; i < s_size/2; ++i) {
            std::swap(s[i], s[s_size-1-i]);
        }
    }
};