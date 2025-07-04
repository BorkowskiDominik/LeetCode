class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        int freq1[26] = {}, freq2[26] = {};
        bool seen1[26] = {}, seen2[26] = {};

        for (char c : word1) {
            freq1[c - 'a']++;
            seen1[c - 'a'] = true;
        }

        for (char c : word2) {
            freq2[c - 'a']++;
            seen2[c - 'a'] = true;
        }

        // warunek 1: ten sam zestaw znaków
        for (int i = 0; i < 26; ++i)
            if (seen1[i] != seen2[i])
                return false;

        // warunek 2: identyczne multizbiory liczności
        std::sort(freq1, freq1 + 26);
        std::sort(freq2, freq2 + 26);

        for (int i = 0; i < 26; ++i)
            if (freq1[i] != freq2[i])
                return false;

        return true;
    }
};
