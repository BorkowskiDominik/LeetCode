class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp = grid.front();
        std::partial_sum(dp.begin(), dp.end(), dp.begin());

        for (int i = 1; i < grid.size(); ++i) {
            dp[0] = grid[i][0] + dp[0];

            for (int j = 1 ; j < dp.size(); ++j) 
                dp[j] = grid[i][j] + std::min(dp[j-1], dp[j]);
        }

        return dp.back();
    }
};