class Solution {
    enum class SIDE {BUY, SELL};
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k == 0) return 0;

        // DP Array with columns:
        // Buy 1 | Sell 1 | Buy 2 | Sell 2 | ... | Buy k | Sell k |
        std::vector<int> dp (k*2, INT_MIN);

        for (auto price : prices) {
            dp[0] = std::max(dp[0], -price);
            for (int j = 1; j < dp.size(); ++j) {
                auto side = (j%2) ? SIDE::SELL : SIDE::BUY;
                if (side == SIDE::BUY) {
                    dp[j] = std::max(dp[j], dp[j-1] - price);
                } else {
                    dp[j] = std::max(dp[j], dp[j-1] + price);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};