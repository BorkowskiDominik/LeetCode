class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int grid_size = triangle.back().size();
        if (grid_size == 1) return triangle.front().front();

        vector<vector<int>> dp_grid(grid_size);
        dp_grid.back() = triangle.back();

        for (int i = 0; i < grid_size-1; ++i) {
            dp_grid[i] = vector<int>(i+1, INT_MAX);
        }

        for (int row = grid_size-1; row > 0; --row) {
            auto row_size = triangle[row].size();
            for (int j = 0; j < row_size; ++j) {
                if (j-1 >= 0) 
                    dp_grid[row-1][j-1] = std::min(dp_grid[row-1][j-1], dp_grid[row][j]+triangle[row-1][j-1]);
                if (j < row_size-1) 
                    dp_grid[row-1][j] = std::min(dp_grid[row-1][j], dp_grid[row][j]+triangle[row-1][j]);
            }
        }

        return dp_grid.front().front();
    }
};