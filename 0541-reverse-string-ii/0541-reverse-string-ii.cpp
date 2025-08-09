class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            std::reverse(s.begin()+i, std::min(s.begin()+i+k, s.end()));
        }
        return s;
    }
};