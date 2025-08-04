class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Sprawdzamy 4 sąsiadów
                    if (i == 0 || grid[i-1][j] == 0) ++perimeter;
                    if (i == rows-1 || grid[i+1][j] == 0) ++perimeter;
                    if (j == 0 || grid[i][j-1] == 0) ++perimeter;
                    if (j == cols-1 || grid[i][j+1] == 0) ++perimeter;
                }
            }
        }

        return perimeter;
    }
};

// MORE COMPLEX SOLUTION WITH BFS ALGORITHM (Much slower) :

// constexpr std::array<std::pair<int, int>, 4> NEIGHBORS {{{-1,0}, {1,0}, {0, 1}, {0, -1}}};

// struct PairHash {
//     std::size_t operator()(const std::pair<int, int>& p) const {
//         // prosty i skuteczny sposób
//         return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
//     }
// };

// class Solution {
//     std::pair<int, int> _findIsland(vector<vector<int>>& grid) {
//         for (int i = 0; i < grid.size(); ++i)
//             for (int j = 0; j < grid[0].size(); ++j) {
//                 if (grid[i][j]) 
//                     return {i, j};
//             }
//         return {-1, -1};
//     }

// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;

//         auto isValidCell = [&grid](int x, int y) {
//             return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
//         };

//         std::queue<std::pair<int, int>> q;
//         std::unordered_set<std::pair<int, int>, PairHash> visited;

//         auto start = _findIsland(grid);
//         q.push(start);
//         visited.insert(start);

//         int perimeter = 0;

//         while (!q.empty()) {
//             auto [sx, sy] = q.front(); q.pop();

//             for (auto [dx, dy] : NEIGHBORS) {
//                 int x = sx + dx, y = sy + dy;

//                 if (!isValidCell(x, y) || grid[x][y] == 0) {
//                     ++perimeter;
//                 } else if (!visited.contains({x, y})) {
//                     visited.insert({x, y});
//                     q.push({x, y});
//                 }
//             }
//         }

//         return perimeter;
//     }
// };