class Solution {
    using TVb = vector<bool>;
    using TVVb = vector<TVb>;
    using TVVc = vector<vector<char>>;
    using TCoords = std::pair<int, int>;
    using TArrNeighbour = std::array<std::pair<int, int>, 4>;

public:

    void explore(TCoords coords, TVVc& board, TVVb& visited) {
        if (visited[coords.first][coords.second]) return;
        if (board[coords.first][coords.second] == 'X') return;
    
        auto is_valid_coords = [&board](int x, int y) {
            return x >= 0 && y >= 0 && x < board.size() && y < board.front().size();
        };
        std::vector<TCoords> que;
        que.push_back(coords);        
        visited[coords.first][coords.second] = true;
        while(!que.empty()) {
            auto [x, y] = que.back(); que.pop_back();
            for (auto [nx, ny] : TArrNeighbour{{{x+1, y},{x-1, y},{x, y+1},{x, y-1}}}) {
                if (is_valid_coords(nx, ny) && !visited[nx][ny] && board[nx][ny] == 'O') {
                    que.push_back({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    void solve(TVVc& board) {
        TVVb visited(board.size(), vector<bool>(board.front().size(), false));
        // explore fields that are on the edge
        int rows = board.size(), cols = board.front().size();

        for (int i = 0; i < rows; ++i) {
            explore({i, 0     }, board, visited);
            explore({i, cols-1}, board, visited);
        }
        for (int j = 1; j < cols-1; ++j) {
            explore({0,      j}, board, visited);
            explore({rows-1, j}, board, visited);
        }
        // zero all other areas with "O" that has not been visited => so it's surrounded
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols -1; ++j) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        } 
    }
};