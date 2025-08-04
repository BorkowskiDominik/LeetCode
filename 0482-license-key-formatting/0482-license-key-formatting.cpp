class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string out;
        out.reserve(s.size() + s.size() / k);

        int pos = s.size();
        int groupSize = 0;
        while (pos-- > 0) {
            if (s[pos] != '-') {
                if (groupSize == k) {
                    out.push_back('-');
                    groupSize = 0;
                }
                out.push_back(toupper(s[pos]));
                ++groupSize;
            }
        }

        return string(out.rbegin(), out.rend());
    }
};