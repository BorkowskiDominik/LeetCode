class Solution {
public:
    // Hash funkcja dla vector<int>
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = v.size();
            for (int num : v) {
                seed ^= hasher(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    int equalPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::unordered_map<std::vector<int>, int, VectorHash> row_freq;

        for (const auto& row : grid)
            ++row_freq[row];

        int pairs = 0;
        std::vector<int> column(n);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i)
                column[i] = grid[i][j];
            pairs += row_freq[column];
        }

        return pairs;
    }
};

// Naive Solution
// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         auto n = grid.size();
//         vector<int> column(n, 0);

//         int pairs = 0;

//         for (int j = 0; j < n; ++j) {
//             for (int i = 0; i < n; ++i)
//                 column[i] = grid[i][j];
//             pairs += std::count(grid.begin(), grid.end(), column);
//         }
//         return pairs;
//     }
// };