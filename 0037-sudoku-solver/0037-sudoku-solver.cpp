constexpr int BOARD_SIZE = 9;

class Solution {
    using TVVC = vector<vector<char>>;
    using TVPII = std::vector<std::pair<int, int>>;
    using TVPIIt = std::vector<std::pair<int, int>>::iterator;

    void _printMissing (TVPIIt beg, TVPIIt end) {
        for ( ; beg < end; ++beg) {
            cout << "<" << beg->first << "," << beg->second << "> ";
        }
        cout << endl;
    }

    void _printBoard (const TVVC& board) {
        for (const auto& v : board){
            for (char c: v)
                cout << c;
            cout << endl;
        }
            
    }

    std::bitset<10> getCandidates(const TVVC& board, std::pair<int, int> pos) {
        auto [row, col] = pos;
        std::bitset<10> result(0b11111'11111);
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (isdigit(board[row][i])) {
                result[board[row][i]-'0'] = false;
            }
            if (isdigit(board[i][col])) {
                result[board[i][col]-'0'] = false;
            }
        }
        int sx = row - row % 3;
        int sy = col - col % 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (isdigit(board[sx+i][sy+j]))
                    result[board[sx+i][sy+j]-'0'] = false;

        return result;
    }

    bool backtrack(TVVC& board, TVPIIt miss_beg, TVPIIt miss_end) {
        if (miss_beg >= miss_end) {
            return true;
        }
        
        auto candidates = getCandidates(board, *miss_beg);
        auto [row, col] = *miss_beg;
        for (int i = 1; i <= BOARD_SIZE; ++i) {
            if (candidates[i]) {                
                board[row][col] = '0' + i;
                if (backtrack(board, miss_beg + 1, miss_end))
                    return true;
            }
        }
        board[row][col] = '.';
        return false;
    }
public:
    void solveSudoku(TVVC& board) {
        TVPII missing; // vector used for backtracking 
        missing.reserve(81); 
        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j)
                if (board[i][j] == '.')
                    missing.push_back({i, j});

        backtrack(board, missing.begin(), missing.end());
    }
};