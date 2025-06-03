// #define CYCLE_BOARD;

class Solution {
    using TVectInt = vector<vector<int>>;

    void _flush_state();
    void _calc_new_state();
    int _new_state(int is_alive, int alive_neighbours);
    int _alive_neighbours(int r, int c);
    void _normalize(int& r, int& c);
    bool _is_valid_cell(int r, int c);

public:
    void gameOfLife(TVectInt& board);

private:
    static constexpr std::array<std::pair<int, int>, 8> _neighbours {{
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    }};
    TVectInt* p_board;
    std::pair<int, int> _board_size;
};

void Solution::gameOfLife(TVectInt& board) {
    p_board = &board;
    _board_size = {p_board->size(), p_board->front().size()};
    // we have int as type to represent 0 and 1
    // so we can use its unused bits to represent new state
    _calc_new_state();
    _flush_state();
    p_board = nullptr;
    _board_size = {0, 0};
}

[[maybe_unused]]
void Solution::_normalize(int& r, int& c) {
    if (r < 0) r = _board_size.first - 1;
    else if (r >= _board_size.first ) r = 0;
    if (c < 0 ) c = _board_size.second - 1;
    else if (c >= _board_size.second ) c = 0;
}

[[maybe_unused]]
bool Solution::_is_valid_cell(int r, int c) {
    return  r >= 0                  &&
            r < _board_size.first   &&
            c >= 0                  &&
            c < _board_size.second;
}

int Solution::_alive_neighbours(int r, int c) {
    int alive = 0;
    for(const auto& n : _neighbours) {
        int x = r + n.first, y = c + n.second;
        #ifdef CYCLE_BOARD
            _normalize(x, y);
            alive += (*p_board)[x][y] & 1; 
        #else
            if(_is_valid_cell(x, y))
                alive += (*p_board)[x][y] & 1; 
        #endif
    }
    return alive;
}

int Solution::_new_state(int is_alive, int alive_neighbours) {
    if (is_alive) {
        if (alive_neighbours < 2 || alive_neighbours > 3)
            return 0;
        return 1;
    }
    return alive_neighbours == 3; 
}

void Solution::_calc_new_state() {
    for (int i = 0; i < _board_size.first; ++i) {
        for (int k = 0; k < _board_size.second; k++) {
            int alive_neighbours = _alive_neighbours(i, k);
            int is_alive = (*p_board)[i][k] & 1;
            (*p_board)[i][k] += (_new_state(is_alive, alive_neighbours) << 1);
        }
    }
}

void Solution::_flush_state() {
    for(auto& row: *p_board)
        for(auto& el: row)
            el >>= 1;
}