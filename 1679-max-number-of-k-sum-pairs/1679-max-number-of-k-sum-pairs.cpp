class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;
        unordered_map<int, int> counter;
        counter.reserve(nums.size());
        for_each(nums.begin(), nums.end(), [&counter](int n){++counter[n];});

        int operations = 0;
        for (auto [number, cnt] : counter) {
            if (k-number == number) {
                operations += cnt / 2;
                counter[number] = 0;
            }
            else if (counter.contains(k-number) && counter.at(k-number)) {
                operations += std::min(cnt, counter.at(k-number));
                counter[number] = 0;
                counter[k-number] = 0;
            }
        }
        return operations;
    }
};

// Verison from chatGPT that suggests that that maybe faster than my version:
// however my code has better runtime that below code:
// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         int operations = 0;

//         for (int n : nums) {
//             int complement = k - n;
//             if (freq[complement] > 0) {
//                 ++operations;
//                 --freq[complement];
//             } else {
//                 ++freq[n];
//             }
//         }

//         return operations;
//     }
// };
