class Solution {
    int kadane(const vector<int>& nums, bool reverse = false) {
        int n_size = nums.size();
        auto start_val = reverse ? -nums[0] : nums[0];
        int global_sum = start_val;
        int curr_sum = start_val;
        for (size_t i = 1; i < nums.size(); ++i) {
            auto el = reverse ? -nums[i] : nums[i];
            curr_sum = std::max(el, curr_sum + el);
            global_sum = std::max(global_sum, curr_sum);
        }
        return global_sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        auto total = std::accumulate(nums.begin(), nums.end(), 0);
        auto max_k = kadane(nums, false);
        auto min_k = kadane(nums, true);
        if (min_k == -total) 
            return max_k;

        return std::max(max_k, total + min_k);
    }
};