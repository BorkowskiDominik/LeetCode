class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int cash = 0;               // maksymalny zysk bez akcji
        int hold = -prices[0];      // maksymalny zysk z akcją kupioną 1. dnia

        for (int i = 1; i < n; ++i) {
            cash = std::max(cash, hold + prices[i] - fee); // sprzedaż
            hold = std::max(hold, cash - prices[i]);       // kupno
        }

        return cash;
    }
};
