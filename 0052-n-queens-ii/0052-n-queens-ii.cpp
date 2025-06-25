struct Point {
    int x;
    int y;
};

class Board {
    using TVB = std::vector<bool>;
    int _size;
    TVB aval_cols;
    TVB aval_diags_r;
    TVB aval_diags_f;

    inline int _to_diag_r(const Point& p) const {
        return p.y - p.x + _size - 1;
    }

    inline int _to_diag_f(const Point& p) const {
        return p.x + p.y;
    }

public:
    Board(int n)
        : _size(n),
          aval_cols(n, true),
          aval_diags_r(2 * n - 1, true),
          aval_diags_f(2 * n - 1, true) {}

    inline int size() const { return _size; }

    inline bool canPlace(const Point& pos) const {
        return aval_cols[pos.y]
            && aval_diags_r[_to_diag_r(pos)]
            && aval_diags_f[_to_diag_f(pos)];
    }

    inline void place(const Point& pos) {
        aval_cols[pos.y] = false;
        aval_diags_r[_to_diag_r(pos)] = false;
        aval_diags_f[_to_diag_f(pos)] = false;
    }

    inline void pop(const Point& pos) {
        aval_cols[pos.y] = true;
        aval_diags_r[_to_diag_r(pos)] = true;
        aval_diags_f[_to_diag_f(pos)] = true;
    }
};

class Solution {
    void backtrack(int row, Board& board, int& counter) {
        if (row == board.size()) {
            ++counter;
            return;
        }
        for (int col = 0; col < board.size(); ++col) {
            Point p{row, col};
            if (board.canPlace(p)) {
                board.place(p);
                backtrack(row + 1, board, counter);
                board.pop(p);
            }
        }
    }

public:
    int totalNQueens(int n) {
        Board board(n);
        int counter = 0;
        backtrack(0, board, counter);
        return counter;
    }
};
