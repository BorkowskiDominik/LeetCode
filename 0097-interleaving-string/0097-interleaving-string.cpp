class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        int m = s1.size(), n = s2.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;
        for (int j = 1; j <= n; ++j)
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n];
    }
};
