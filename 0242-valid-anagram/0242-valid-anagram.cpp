class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> counter {};
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); ++i) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }

        return all_of(counter.begin(), counter.end(), [](int i){ return i == 0; });
    }
};