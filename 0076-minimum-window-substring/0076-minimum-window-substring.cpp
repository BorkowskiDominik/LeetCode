class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        std::array<int, 128> pattern_counter{};
        for (char c : t) ++pattern_counter[c];

        std::array<int, 128> window_count{};
        int required = 0;
        for (int count : pattern_counter)
            if (count > 0) ++required;

        int formed = 0;
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int min_start = 0;

        while (right < s.size()) {
            char c = s[right];
            ++window_count[c];

            if (pattern_counter[c] > 0 && window_count[c] == pattern_counter[c])
                ++formed;

            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char lc = s[left];
                --window_count[lc];
                if (pattern_counter[lc] > 0 && window_count[lc] < pattern_counter[lc])
                    --formed;

                ++left;
            }

            ++right;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
