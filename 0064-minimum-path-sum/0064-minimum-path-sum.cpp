class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {        
        auto print = [](const auto& v){ for (auto e : v) cout << e << " "; cout << endl;};
        vector<int> dp = grid.front();

        for (int j = 1; j < dp.size(); ++j) {
            dp[j] += dp[j-1];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 0 ; j < dp.size(); ++j) {
                if (j == 0)
                    dp[j] = grid[i][j] + dp[j];
                else
                    dp[j] = grid[i][j] + std::min(dp[j-1], dp[j]);
            }
        }


        return dp.back();
    }
};