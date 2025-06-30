enum class ALGORITHM {FULL, SHORT};
constexpr auto ALGO = ALGORITHM::SHORT;


class Solution {
    int minCostClimbingStairsFullDp(const vector<int>& cost) const;
    int minCostClimbingStairsShortDp(const vector<int>& cost) const;

public:
    int minCostClimbingStairs(const vector<int>& cost) const {
        if constexpr(ALGO == ALGORITHM::FULL)
            return minCostClimbingStairsFullDp(cost);
        if constexpr(ALGO == ALGORITHM::SHORT)
            return minCostClimbingStairsShortDp(cost);
        return 0;
    }
};

int Solution::minCostClimbingStairsShortDp(const vector<int>& cost) const {
    size_t n = cost.size();
    std::array<int, 3> dp = {0, cost[0], cost[1]};
    for (int i = 2; i < n; ++i) {
        std::move(dp.begin()+1, dp.end(), dp.begin());
        dp[2] = cost[i] + std::min(dp[0], dp[1]);
    }
    return std::min(dp[1], dp[2]);
}

int Solution::minCostClimbingStairsFullDp(const vector<int>& cost) const {
    size_t n = cost.size();
    vector<int> dp(n + 1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n + 1; ++i) {
        int tile_cost = (i < n) ? cost[i] : 0;
        dp[i] = tile_cost + std::min(dp[i-1], dp[i-2]);
    }
    return dp.back();
}