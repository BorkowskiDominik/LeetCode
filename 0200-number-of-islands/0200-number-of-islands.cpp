// #define DFS
#define BFS

#if defined(DFS)
class Solution {
private:
    void explore(std::pair<int, int> coords, vector<vector<char>>& grid) {
        auto& [x,y] = coords;
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid.front().size())
            return;
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            explore({x-1, y}, grid);
            explore({x+1, y}, grid);
            explore({x, y-1}, grid);
            explore({x, y+1}, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // If we can't modify input vector, create visited array
        //std::vector<vector<bool>> visited(grid.size(), std::vector<bool>(grid.front().size(), false));
        int islands{};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    explore({i,j}, grid);
                }
            }
        }
        return islands;
    }
};
#elif defined(BFS)// BFS soluction
class Solution {
private:
    void explore(std::pair<int, int> coords, vector<vector<char>>& grid) {
        using TArray = std::array<std::pair<int, int>, 4>;
        auto valid_coords = [&grid](int x, int y){return (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size());};

        std::queue<std::pair<int, int>> que;
        que.push(coords);
        grid[coords.first][coords.second] = '0';

        while(!que.empty()) {
            auto [x,y] = que.front(); que.pop();
            for (auto [nx, ny] : TArray { {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}} }) {
                if (valid_coords(nx, ny) && grid[nx][ny]=='1') {
                    que.push({nx, ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands{};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    explore({i,j}, grid);
                }
            }
        }
        return islands;
    }
};
#else
    #error "Mode not selected"
#endif