template<typename T>
struct TPoint {
    T x;
    T y;
};
using Point = TPoint<int>;
ostream& operator<<(ostream& o, vector<vector<int>> m);

template<typename T>
ostream& operator<<(ostream& o, const TPoint<T>& p);


class Solution {
    using TMatrix = vector<vector<int>>;

    Point _rotate(Point p) {
        if (!_matrix) return p;
        
        double new_x = _center.x + p.y - _center.y;
        double new_y = _center.y - p.x + _center.x;
        return {static_cast<int>(new_x), static_cast<int>(new_y)};
    };

    TMatrix* _matrix;
    int _size;
    TPoint<double> _center;

public:    
    void rotate(TMatrix& matrix) {
        _matrix = &matrix;
        _size = _matrix->size();
        _center = { (_size-1)/ 2.0, (_size-1) / 2.0 };
        for (int i = 0; i < _size; ++i) {
            for (int j = i; j < _size-i-1; ++j) {
                Point curr {i, j};
                for (int holder = 0, r = 0; r < 5; ++r) {
                    Point next = _rotate(curr);
                    int old_value = matrix[curr.x][curr.y];
                    matrix[curr.x][curr.y] = holder;
                    holder = old_value;
                    curr = next;
                }
            }
        }
        _matrix = nullptr;
    }

};

ostream& operator<<(ostream& o, vector<vector<int>> m) {
    for(auto const& r: m){
        for (auto const& c: r)
            cout << c << " ";
        cout << endl;
    }
    return o;
}

template<typename T>
ostream& operator<<(ostream& o, const TPoint<T>& p) {
    o << "(" << p.x << ":" << p.y << ")"; 
    return o;
}
