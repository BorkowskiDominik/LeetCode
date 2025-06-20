class Solution {
    const vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool backtrack(int x, int y, int idx,
                   const vector<vector<char>>& board,
                   vector<vector<bool>>& visited,
                   const string& word) {
        if (idx == word.size()) return true;

        for (const auto& [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
                continue;

            if (visited[nx][ny] || board[nx][ny] != word[idx])
                continue;

            visited[nx][ny] = true;
            if (backtrack(nx, ny, idx + 1, board, visited, word))
                return true;
            visited[nx][ny] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, const string& word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

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
