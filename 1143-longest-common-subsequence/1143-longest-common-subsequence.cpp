class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<int> dp(n2+1);

        for (int i = 1; i <= n1; ++i) {
            int prev = 0; // equivalent to dp[j-1] from previous row
            for (int j = 1; j <= n2; ++j) {
                int temp = dp[j];
                if (text1[i-1] == text2[j-1])
                    dp[j] = prev + 1;
                else                    
                    dp[j] = std::max(dp[j], dp[j-1]);
                prev = temp;
            }
        }
        return dp.back();
    }
};