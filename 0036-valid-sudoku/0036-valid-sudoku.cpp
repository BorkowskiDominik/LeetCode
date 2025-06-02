class Solution {
    using Vector2DChar = vector<vector<char>>;

    class MapIterator {
        protected:
            std::pair<int, int> _pos;
            const Vector2DChar& _map;
            virtual void _move_cursor() = 0;
        public:
            MapIterator(const Vector2DChar& map, std::pair<int, int> pos = {-1, -1}): _map(map), _pos(pos) {}
            virtual optional<char> next() {
                if(_pos.first < _map.size() && _pos.second < _map[_pos.first].size())
                {
                    char result = _map[_pos.first][_pos.second];
                    _move_cursor();
                    return result;
                }
                return nullopt;
            }
            virtual ~MapIterator() = default;
    };

    class RowIterator : public MapIterator {
        protected:
            virtual void _move_cursor() override {
                _pos.second++; 
            }
        public:
            RowIterator(const Vector2DChar& map, int row): MapIterator(map, {row, 0}) {}
    };

    class ColIterator : public MapIterator {
        protected:
            virtual void _move_cursor() override {
                _pos.first++; 
            }
        public:
            ColIterator(const Vector2DChar& map, int col): MapIterator(map, {0, col}) {}
    };

    class SquareIterator : public MapIterator {
        std::pair<int, int> _init_pos;
        int _element;
    protected:
        virtual void _move_cursor() override {
            ++_element;
            if (_element < 9)
                _pos = { _init_pos.first + _element / 3, _init_pos.second + _element % 3 };
            else
                _pos = {10,10}; // set to invalid value
        }
    public:
        SquareIterator(const Vector2DChar& map, int square)
            : MapIterator(map), _init_pos({(square / 3) * 3, (square % 3) * 3}), _element(0) {
            _pos = _init_pos;
        }
    };

    bool _verify(MapIterator& it) {
        std::bitset<10> seen(0);
        while(auto value = it.next()) {
            if (*value=='.') {
                continue;
            }
            int digit = *value - '0';
            if (seen[digit])
                return false;
            seen[digit] = true;
        }
        return true;
    }

    bool _verify_rows(Vector2DChar& board) {
        for (int i=0; i<board.size(); ++i) {
            auto iterator = RowIterator(board, i);
            if(!_verify(iterator))
                return false;
        }
        return true;
    }

    bool _verify_cols(Vector2DChar& board) {
        for (int i=0; i<board.size(); ++i) {
            auto iterator = ColIterator(board, i);
            if(!_verify(iterator))
                return false;
        }
        return true;

    }

    bool _verify_squares(Vector2DChar& board) {
        for (int i=0; i<board.size(); ++i) {
            auto iterator = SquareIterator(board, i);
            if(!_verify(iterator))
                return false;
        }
        return true;
    }


public:
    bool isValidSudoku(Vector2DChar& board) {
         return _verify_rows(board) && _verify_cols(board) && _verify_squares(board);
    }
};