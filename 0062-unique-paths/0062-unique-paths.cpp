class Solution {
public:
    int uniquePathsDP(int m, int n) {
        std::vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[j] = dp[j-1] + dp[j];
        }
        return dp.back();
    }

    int uniquePaths(int m, int n) {
        // number of combinations
        // C(m + n - 2, m - 1) = (m+n-2)! / [(m-1)! * (n-1)!]
        long long res = 1;
        for (int i = 1; i <= m - 1; ++i) {
            res = res * (n - 1 + i) / i;
        }
        return static_cast<int>(res);
    }
};