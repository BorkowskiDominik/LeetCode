enum class ALGO {DP, GRAPH};
constexpr auto METHOD = ALGO::GRAPH;

class Solution {
public:
    int numSquares(int n) { 
        if (METHOD == ALGO::GRAPH)
            return numSquaresGraph(n);
        
        if (METHOD == ALGO::DP)
            return numSquaresDP(n);
        
        return 0; // algorihtm not selected
    }

    int numSquaresDP(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i*i <= n; ++i) {
            int sq = i*i;
            for (int j = sq; j <= n; ++j) {
                if (dp[j - sq] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - sq] + 1);
            }
        }

        return dp[n];
    }

    int numSquaresGraph(int n) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int level = 0; // liczba przejść (liczba kwadratów)

        while (!q.empty()) {
            int size = q.size();
            ++level;

            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();

                for (int j = 1; j*j + current <= n; ++j) {
                    int next = current + j*j;
                    if (next == n)
                        return level;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return level; // fallback, teoretycznie nigdy nieosiągalne
    }
};
