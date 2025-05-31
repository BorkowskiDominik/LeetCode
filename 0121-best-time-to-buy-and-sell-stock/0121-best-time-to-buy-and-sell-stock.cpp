class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int max_profit = 0;
        int min = prices.front(), max = prices.front();

        for(int i=1; i < prices.size(); ++i)
        {
            // if new local minimum found, reset max and min values to restart calculations
            if(prices[i] < min)
            {
                min = prices[i];
                max= prices[i];
            }
            if(prices[i] > max)
            {  
                max = prices[i];
                max_profit = std::max(max_profit, max-min);
            }
        }
        return max_profit;
    }
};