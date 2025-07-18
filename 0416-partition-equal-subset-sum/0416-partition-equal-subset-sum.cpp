class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2) return false; // for sure we can't parition odd number
        int half = total_sum / 2;
        std::vector<bool> can_reach(half+1, false);
        can_reach[0] = true;

        auto n_can = can_reach.size();
        for (auto n : nums) {
            for (int i = half; i >= n; --i) {
                if (can_reach[i - n])
                    can_reach[i] = true;
            }
        }
        return can_reach.back();
    }
};