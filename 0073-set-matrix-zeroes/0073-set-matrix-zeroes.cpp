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
        bool first_row_zero = false, first_col_zero = false;

        first_row_zero = std::find(first_row.begin(), first_row.end(), 0) != first_row.end();

        for (int j = 0; j < rows; ++j) {
            if (0 == matrix[j][0]) {
                first_col_zero = true;
                break;
            }
        }
        // mark rows and cols to zero
        for (int i = 1; i < rows; ++i) {
            for (int k = 1; k < cols; ++k) {
                if (0 == matrix[i][k]) {
                    matrix[0][k] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //clear rows
        for_each( matrix.begin()+1, matrix.end(),
            [&](vector<int> & row){
                if (0 == row[0]) std::fill(row.begin()+1, row.end(), 0); 
            }
        );

        // clear cols
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
            for (int c = 0; c < rows; ++c) {
                matrix[c][0] = 0;
            }
        }
    }
};