class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        std::array<int, 256> s_to_t{};
        std::array<int, 256> t_to_s{};

        for (int i = 0; i < s.size(); ++i) {
            unsigned char cs = s[i], ct = t[i];

            if ((s_to_t[cs] && s_to_t[cs] != ct) ||
                (t_to_s[ct] && t_to_s[ct] != cs))
                return false;

            s_to_t[cs] = ct;
            t_to_s[ct] = cs;
        }
        return true;
    }
};
