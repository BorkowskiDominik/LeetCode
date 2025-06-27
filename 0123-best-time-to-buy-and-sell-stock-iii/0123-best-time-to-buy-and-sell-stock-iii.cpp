class Solution {
    enum class Side {BUY, SELL};
public:
    int maxProfit(vector<int>& prices) {
        // Dynamic programing array: 
        // ## First Buy ## First Sell ## Second Buy ## Second Sell ##
        std::array<int, 4> dp{INT_MIN, INT_MIN, INT_MIN, INT_MIN};

        for (auto price : prices) {
            dp[0] = std::max(-price, dp[0]);
            for (int j = 1; j < dp.size(); ++j) {
                auto side = (j%2) ? Side::SELL : Side::BUY;
                if (side == Side::BUY) {
                    dp[j] = std::max(dp[j], dp[j-1] - price);
                } else {
                    dp[j] = std::max(dp[j], dp[j-1] + price);
                }
            }
        }

        // no position is also a position ;d
        // if there will be no profitable positions there always be some 0 in final row
        // to reflect such case
        return *std::max_element(dp.begin(), dp.end());
    }
};