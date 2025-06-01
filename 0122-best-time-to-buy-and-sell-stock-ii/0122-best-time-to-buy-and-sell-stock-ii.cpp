class Solution {
public:
    // int maxProfit_first_version(vector<int>& prices) {
    //     int profit = 0;
    //     int buy = 0;
    //     bool has_share = false;
    //     for (int i = 0; i < prices.size(); ++i)
    //     {
    //         int next_price = i == prices.size()-1 ? 0 : prices[i+1];
    //         int curr_price = prices[i];
    //         if (!has_share && next_price > curr_price)
    //         {
    //             buy = curr_price;
    //             has_share = true;
    //         }
    //         if(next_price < curr_price && has_share)
    //         {
    //             profit += (curr_price - buy);
    //             has_share = false;
    //         }
    //     }
    //     return profit;
    // }

    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {  
            if (prices[i] > prices[i-1]) {
                profit +=  prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};