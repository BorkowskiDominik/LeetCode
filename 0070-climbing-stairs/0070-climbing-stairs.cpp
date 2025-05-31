class Solution {
public:
    // dynamic programming with array
    int climbStairs_DP(int n) {
        vector<int> stairs(n+2);
        stairs[0]=1;
        for(int i = 0; i < n; ++i )
        {
            stairs[i+1] += stairs[i];
            stairs[i+2] += stairs[i];
        }
        return stairs[n];
    }
    // dynamic programming with iterative way
    int climbStairs(int n) {
        if (n <= 1)
            return 1;

        int step_old = 1;  // ways to reach step 0
        int step_prev = 1;  // ways to reach step 1

        for (int i = 2; i <= n; ++i) {
            int step_curr = step_old + step_prev;
            step_old = step_prev;
            step_prev = step_curr;
        }

        return step_prev;
    }
};
