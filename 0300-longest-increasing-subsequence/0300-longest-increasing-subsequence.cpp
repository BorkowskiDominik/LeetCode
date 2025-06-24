enum class ALGORITHM {NAIVE, OPTIMAL};
constexpr auto ALGO = ALGORITHM::OPTIMAL;

class Solution {
public:
    // naive - O(n^2)
    int lengthOfLISNaive(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto size = nums.size();
        vector<int> dp(size, 1);
        
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) {
                    dp[j] = std::max(dp[j], dp[i]+1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }

    // Optimal O(n log n)
    int lengthOfLISOptimal(const vector<int>& nums) {
        vector<int> tails;
        tails.reserve(nums.size());
        for (auto n : nums) {
            if (auto it = std::lower_bound(tails.begin(), tails.end(), n); it == tails.end()) 
                tails.emplace_back(n);
            else
                *it = n;
        }

        return tails.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        if constexpr(ALGO == ALGORITHM::NAIVE) {
            return lengthOfLISNaive(nums);
        } else if constexpr(ALGO == ALGORITHM::OPTIMAL) {
            return lengthOfLISOptimal(nums);
        }
        return 0;
     }
};