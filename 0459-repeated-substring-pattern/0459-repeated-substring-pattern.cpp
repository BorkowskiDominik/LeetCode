// KMP: (Knuth–Morris–Pratt)
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int n = s.size();
//         vector<int> lps(n, 0); // Longest Prefix Suffix
//         int len = 0; // długość poprzedniego najdłuższego prefiksu-sufiksu
//         int i = 1;

//         while (i < n) {
//             if (s[i] == s[len]) {
//                 lps[i++] = ++len;
//             } else if (len > 0) {
//                 len = lps[len - 1];
//             } else {
//                 lps[i++] = 0;
//             }
//         }

//         int last = lps[n - 1];
//         return last > 0 && n % (n - last) == 0;
//     }
// };

// My naive solution (even though 100%)
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