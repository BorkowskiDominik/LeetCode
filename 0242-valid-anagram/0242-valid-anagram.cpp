class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 256> counter;
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); ++i) {
            counter[s[i]]++;
            counter[t[i]]--;
        }

        return all_of(counter.begin(), counter.end(), [](int i){ return i == 0; });
    }
};