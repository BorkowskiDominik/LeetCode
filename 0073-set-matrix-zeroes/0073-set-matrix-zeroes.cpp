class Solution {
public:

    // Runtime 100%,  Memory 50%
    void setZeroes_bruteforce(vector<vector<int>>& matrix) {
        std::unordered_set<int> _rows_to_clear;
        std::unordered_set<int> _cols_to_clear;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(!matrix[i][j]) {
                    _rows_to_clear.insert(i);
                    _cols_to_clear.insert(j);
                }
            }
        }
        // clear rows
        std::for_each(_rows_to_clear.begin(), _rows_to_clear.end(), [&](int i){
            std::for_each(matrix[i].begin(), matrix[i].end(), [](int& i){i = 0;});
        });

        std::for_each(_cols_to_clear.begin(), _cols_to_clear.end(), [&](int j){
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][j] = 0;
            }
        });
    }

    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<int>& first_row = matrix.front();
        int rows = matrix.size(), cols = first_row.size();

        bool first_row_zero = std::any_of(matrix[0].begin(), matrix[0].end(),
                                    [](int val) { return val == 0; });

        bool first_col_zero = std::any_of(matrix.begin(), matrix.end(),
                                      [](const std::vector<int>& row) { return row[0] == 0; });


        // mark rows and cols to zero
        for (int i = 1; i < rows; ++i) {
            for (int k = 1; k < cols; ++k) {
                if (0 == matrix[i][k]) {
                    matrix[0][k] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Zero marked rows
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                std::fill(matrix[i].begin() + 1, matrix[i].end(), 0);
            }
        }

        // Zero out marked columns
        for (int c = 1; c < cols; ++c) {
            if (0 == matrix[0][c]) {
                for (int k = 1; k < rows; ++k)
                    matrix[k][c] = 0;
            }
        }

        // clear first row if needed
        if (first_row_zero)
            std::fill(first_row.begin(), first_row.end(), 0);
        
        // clear first column if needed
        if (first_col_zero) {
            for (auto& row : matrix)
                row[0] = 0;
        }
    }
};