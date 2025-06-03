class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for (auto it = nums.begin(); it < nums.end() - 2; ++it) {
            if (it > nums.begin() && *it == *(it - 1))
                continue; // skip duplicates

            auto left = it + 1;
            auto right = nums.end() - 1;

            while (left < right) {
                int sum = *it + *left + *right;
                if (sum == 0) {
                    results.push_back({*it, *left, *right});

                    // skip duplicates
                    while (left < right && *left == *(left + 1)) ++left;
                    while (left < right && *right == *(right - 1)) --right;

                    ++left;
                    --right;
                }
                else if (sum < 0) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }

        return results;
    }
};
