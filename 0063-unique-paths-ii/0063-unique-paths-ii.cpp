class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        // auto print = [](const auto& v){for (auto e: v) cout << e << " "; cout << endl;};

        std::vector<int> dp (obstacleGrid.front().size(), 0);
        dp[0] = obstacleGrid[0][0] == 0;

        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] == 1) 
                dp[0] = 0;

            for (int j = 1; j < dp.size(); ++j) {
                if (obstacleGrid[i][j] == 1) 
                    dp[j] = 0;
                else                
                    dp[j] += dp[j-1];
            }
        }

        return dp.back();
    }
};