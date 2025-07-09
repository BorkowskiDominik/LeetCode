class Solution {
public:
    vector<int> partitionLabels(string s) {
        auto print = [](auto& c){ for (auto e: c) cout << e << " "; cout << endl;};
        auto cti = [](char c){return c-'a';};
        
        std::array<int, 26> counter;
        for_each(s.begin(), s.end(), [&counter] (char c) {++counter[c-'a'];});

        int left = counter[cti(s.front())];

        bitset<26> used_numbers;
        used_numbers.set(cti(s.front()));

        vector<int> results;
        int curr_len = 0;
        for (char c: s) {
            ++curr_len;
            if (used_numbers[cti(c)]) {
                left--;
            } else {
                left += counter[cti(c)]-1;
                used_numbers.set(cti(c));
            }
            if (!left) {
                results.push_back(curr_len);
                curr_len = 0;
            }
        }

        return results;
    }

    // also interesting solution suggested by chatgpt,
    // in this solution we save in array last occurance of each sign
    // and update end whiel iterating over string
    vector<int> partitionLabelsChat(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); ++i)
            last[s[i] - 'a'] = i;

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};