class Solution {
public:
    void bfs(std::pair<int, int> coords, const vector<vector<char>>& grid, std::vector<vector<bool>>& visited) {
        auto& [x,y] = coords;
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid.front().size())
            return;
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (grid[x][y] == '1') {
            bfs({x-1, y}, grid, visited);
            bfs({x+1, y}, grid, visited);
            bfs({x, y-1}, grid, visited);
            bfs({x, y+1}, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        std::vector<vector<bool>> visited(grid.size(), std::vector<bool>(grid.front().size(), false));
        int islands{};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    islands++;
                    bfs({i,j}, grid, visited);
                }
            }
        }
        return islands;
    }
};