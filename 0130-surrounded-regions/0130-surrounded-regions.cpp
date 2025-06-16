class Solution {
    using TVb = vector<bool>;
    using TVVb = vector<TVb>;
    using TVVc = vector<vector<char>>;
    using TCoords = std::pair<int, int>;
    using TArrNeighbour = std::array<std::pair<int, int>, 4>;

public:

    void explore(TCoords coords, TVVc& board) {
        if (board[coords.first][coords.second] == 'X') return;
    
        auto is_valid_coords = [&board](int x, int y) {
            return x >= 0 && y >= 0 && x < board.size() && y < board.front().size();
        };
        std::vector<TCoords> que;
        que.push_back(coords);        
        board[coords.first][coords.second] = 'S';
        while(!que.empty()) {
            auto [x, y] = que.back(); que.pop_back();
            for (auto [nx, ny] : TArrNeighbour{{{x+1, y},{x-1, y},{x, y+1},{x, y-1}}}) {
                if (is_valid_coords(nx, ny) && board[nx][ny] == 'O') {
                    que.push_back({nx, ny});
                    board[nx][ny] = 'S';
                }
            }
        }
    }

    void solve(TVVc& board) {
        // TVVb visited(board.size(), vector<bool>(board.front().size(), false));
        // explore fields that are on the edge
        int rows = board.size(), cols = board.front().size();

        for (int i = 0; i < rows; ++i) {
            explore({i, 0     }, board);
            explore({i, cols-1}, board);
        }
        for (int j = 1; j < cols-1; ++j) {
            explore({0,      j}, board);
            explore({rows-1, j}, board);
        }
        // zero all other areas with "O" that has not been visited => so it's surrounded
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        } 
    }
};