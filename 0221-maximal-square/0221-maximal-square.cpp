enum class ALGORITHM {ONE_D, TWO_D};
constexpr auto ALGO = ALGORITHM::TWO_D;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { 
        if constexpr(ALGO == ALGORITHM::ONE_D)
            return maximalSquare1D(matrix);
        else
            return maximalSquare2D(matrix);
    }

    int maximalSquare2D(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        size_t r = matrix.size();
        size_t c = matrix.front().size();
        
        int maxSquare = 0; 
        std::vector<vector<int>> dp(r, vector<int>(c));
        
        for (size_t j = 0; j < c; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            maxSquare = std::max(maxSquare, dp[0][j]);
        }

        for (size_t i = 0; i < r; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxSquare = std::max(maxSquare, dp[i][0]);
        }

        for (size_t i = 1; i < r; ++i) {
            for (size_t j = 1; j < c; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                    maxSquare = std::max(maxSquare, dp[i][j]);
                }
            }
        }
        return maxSquare * maxSquare;
    }

    int maximalSquare1D(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        std::vector<int> dp(cols + 1, 0); // +1 by uniknąć specjalnego przypadku dla j==0
        int max_square = 0, prev_diag = 0;

        for (size_t i = 1; i <= rows; ++i) {
            prev_diag = 0;
            for (size_t j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = std::min({dp[j - 1], dp[j], prev_diag}) + 1;
                    max_square = std::max(max_square, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev_diag = temp;
            }
        }

        return max_square * max_square;
    }
};
