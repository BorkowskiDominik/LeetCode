class Solution {
public:
    bool isSubsequence(string s, string t) {
        // t - full string
        // s - subsequence
        auto cursor = 0;
        for(char c : s)
        {
            cursor = t.find(c, cursor);
            if(cursor == string::npos)
                return false;
            ++cursor;
        }
        return true;
    }
};