class Solution {
    class Iterator {
        using TPos = std::pair<int, int>;
        using TIntPairs = std::array<std::pair<int, int>, 4>;
        
        private:
            inline static const TIntPairs _directions {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
            TIntPairs::const_iterator _direction;
            
            const std::vector<std::vector<int>>& _matrix;
            TPos _curr;
            int _min_row, _max_row, _min_col, _max_col;
        
        private:
            bool _is_valid_position(TPos pos) const;
            void _change_direction();

        public: 
            Iterator(const std::vector<std::vector<int>>& matrix);
            std::optional<int> next();
    };
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> spiral;
        spiral.reserve(matrix.size() * matrix.front().size());
        Iterator it(matrix);
        while (auto element = it.next()) {
            spiral.push_back(*element);
        }
        return spiral;
    }
};


Solution::Iterator::Iterator(const std::vector<std::vector<int>>& matrix): 
        _matrix(matrix), 
        _curr({0,0}),
        _min_row(-1),
        _max_row(matrix.size()),
        _min_col(-1),
        _max_col(matrix.front().size()),
        _direction(_directions.cbegin()) {

}

bool Solution::Iterator::_is_valid_position(TPos pos) const {
    int row = pos.first, col = pos.second;
    return row > _min_row && row < _max_row && col > _min_col && col < _max_col;
}

void Solution::Iterator::_change_direction() {
    if (_direction->first == 1)  --_max_col;       // down -> left // right column visied completed
    else if(_direction->first == -1) ++_min_col;   // up -> right // left column completed
    else if (_direction->second == 1) ++_min_row;  // right -> down // top row completed
    else if(_direction->second == -1) --_max_row;  // left -> up // bottom row completed

    ++_direction;
    if (_direction == _directions.cend())
        _direction = _directions.cbegin();
}

std::optional<int> Solution::Iterator::next() {
    if (!_is_valid_position(_curr))
        return nullopt;

    int result = _matrix[_curr.first][_curr.second]; 

    TPos candidate = {
        _curr.first + _direction->first,
        _curr.second + _direction->second
    };

    if (!_is_valid_position(candidate)) {
        _change_direction();
        candidate = {
            _curr.first + _direction->first,
            _curr.second + _direction->second
        };
    }
    _curr = candidate;
    return result;
}
