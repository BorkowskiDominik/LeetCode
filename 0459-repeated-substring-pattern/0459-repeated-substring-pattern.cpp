class Solution {
    bool isBuildOf(string_view s, string_view pattern) {
        int pSize = pattern.size();
        int sSize = s.size();
        if (sSize % pSize)
            return false;
        
        for (int i = pSize; i <= sSize - pSize; i += pSize) {
            if (s.substr(i, pSize) != pattern)
                return false;
        }
        return true;
    }

public:
    bool repeatedSubstringPattern(string_view s) {
        int hl = s.size() / 2;
        for (int i = hl; i >= 1 ; --i) {
            if (isBuildOf(s, s.substr(0, i)))
                return true;
        }
        return false;
    }
};