class Solution {
public:
    vector<int> findAnagrams(string_view s, string_view p) {
        if (!s.size() || !p.size() || p.size() > s.size()) return {};

        int p_size = p.size();
        int s_size = s.size();
        
        std::array<int, 26> p_letters {};
        for (char c : p)
            ++p_letters[c - 'a'];

        
        std::vector<int> idx;
        idx.reserve(s_size - p_size + 1);

        std::array<int, 26> sub_letters {};
        for (int i = 0; i < p_size - 1; ++i)
            ++sub_letters[s[i] - 'a'];

        for (int i = 0; i + p_size <= s_size; ++i) {
            ++sub_letters[s[i+p_size-1]-'a'];

            if (p_letters == sub_letters)
                idx.push_back(i);            

            --sub_letters[s[i]-'a'];
        }
        
        return idx;
    }
};

// debug info:
// auto printA = [](std::array<int, 26>& a) {
//     for (int i = 0; i < 26; ++i) {
//         if (a[i])
//             cout << char(i+'a') << ": " << a[i] << " ";
//     }
//     cout << endl;
// };