class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        istringstream is(s);
        string w;
        is >> w;
        return w.size();
    }
};