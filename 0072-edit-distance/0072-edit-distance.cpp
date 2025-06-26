class Solution {
public:
    // this is Leventein Algorithm/Distance problem
    int minDistance(string word1, string word2) {
        auto m = word1.size();
        auto n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            int cost;
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1])
                    cost = 0;
                else
                    cost = 1;
                
                dp[i][j] = std::min({
                    dp[i-1][j]+1,
                    dp[i][j-1]+1,
                    dp[i-1][j-1] +cost
                });
            }
        }
        return dp.back().back();
    }
};