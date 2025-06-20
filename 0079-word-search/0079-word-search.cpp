class Solution {
    const vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool backtrack(int x, int y, int idx,
                   const vector<vector<char>>& board,
                //    vector<vector<bool>>& visited,
                   vector<vector<uint8_t>>& visited,
                   const string& word) {
        if (idx == word.size()) return true;

        for (const auto& [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
                continue;

            if (visited[nx][ny] || board[nx][ny] != word[idx])
                continue;

            visited[nx][ny] = 1;
            if (backtrack(nx, ny, idx + 1, board, visited, word))
                return true;
            visited[nx][ny] = 0;
        }

        return false;
    }

    bool canBuild(const vector<vector<char>>& board, const string& word) {
        unordered_map<char, int> board_count;
        for (const auto& row : board)
            for (char c : row)
                board_count[c]++;
        for (char c : word){
            if(--board_count[c] < 0)
                return false;
        }        
        return true;
    }

public:
    bool exist(vector<vector<char>>& board, const string& word) {
        if (!canBuild(board, word)) return false;
        int rows = board.size(), cols = board[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<uint8_t>> visited(rows, vector<uint8_t>(cols, 0));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (backtrack(i, j, 1, board, visited, word))
                        return true;
                    visited[i][j] = false;
                }

        return false;
    }
};
