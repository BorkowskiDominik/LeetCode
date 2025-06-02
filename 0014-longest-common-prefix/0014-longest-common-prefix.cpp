class Solution {
    bool _all_same_letters(const vector<string>& strs, int i) {
        if (strs[0].size() <= i) return false;
        char c = strs[0][i];
        for(const auto& s: strs) {
            if(s[i]!=c)
                return false;
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0; 
        while(_all_same_letters(strs, i))
            ++i;
        if (i) {
            return string(strs[0].begin(), strs[0].begin()+i);
        } else {
            return "";
        }
    }
};