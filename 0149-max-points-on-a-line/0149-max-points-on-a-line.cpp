using TPoint = std::pair<int, int>;

class LineChecker {
public:    
    enum class MODE {
        EQUATION,
        VERTICAL
    };

private:
    TPoint p0, p1;
    MODE _mode;
    int _a, _b;
    int _x_const;

public:    
    LineChecker(TPoint p0, TPoint p1): p0(p0), p1(p1) {
        if (p0.first == p1.first) {
            _mode = MODE::VERTICAL;
            _x_const = p1.first;
        } else {            
            _mode = MODE::EQUATION;
            _a = static_cast<double>(p1.second - p0.second) / (p1.first - p0.first);
            _b = p0.second - _a * p0.first;
        }
    }
    bool operator()(const std::vector<int>& other) const {
        assert(other.size() == 2);
        const auto& [x0, y0] = p0;
        if (_mode == MODE::EQUATION) {
            const auto& [x1, y1] = p1;
            return (x1 - x0) * (other[1] - y0) == (y1 - y0) * (other[0] - x0);
        } else if (_mode == MODE::VERTICAL) {
            return other[0] == x0;
        }
        return false; // not using exceptions to not slow down program
    }

    bool operator==(const LineChecker& other) const {
        if (_mode != other.mode())
            return false;
        if (_mode == MODE::VERTICAL)
            return _x_const == other.x_const();
        return std::abs(_a - other.a()) < 1e-8 && std::abs(_b - other.b()) < 1e-8;
    }

    inline MODE mode() const { return _mode; }
    inline double a() const { return _a; }
    inline double b() const { return _b; }
    inline int x_const() const { return _x_const; }
};

namespace std {
    template<>
    struct hash<LineChecker> {
        std::size_t operator()(const LineChecker& line) const {
            std::size_t seed = 0;
            if (line.mode() == LineChecker::MODE::VERTICAL) {
                seed ^= std::hash<int>{}(line.x_const()) + 0x9e3779b9;
            } else {
                seed ^= std::hash<int>{}(static_cast<int64_t>(line.a() * 1e8)) + 0x9e3779b9;
                seed ^= std::hash<int>{}(static_cast<int64_t>(line.b() * 1e8)) + 0x9e3779b9;
            }
            seed ^= std::hash<int>{}(static_cast<int>(line.mode())) + 0x9e3779b9;
            return seed;
        }
    };
}


class Solution {
    using TLines = std::vector<std::pair<int, int>>;
    using TFunctions = std::unordered_set<LineChecker>;
    using TPoints = std::vector<std::vector<int>>;

    [[maybe_unused]]
    void print(const vector<vector<int>>& points) {
        for (const auto& v: points)
            cout << "[" << v[0] << "," << v[1] << "] ";
        cout << endl;
    }

public:
    [[maybe_unused]]
    void sort_points(TPoints& points) {
        std::sort(points.begin(), points.end(), [](const auto& v, const auto& o){
            if (v[0] == o[0])
                return v[1] < o[1];
            return v[0] < o[0];
        });
    }

    void generate_lines(TPoints& points, TFunctions& functions) {
        for (int i = 0; i < points.size()-1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x0 = points[i][0], y0 = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];
                
                functions.insert(LineChecker({x0, y0}, {x1, y1}));
            }
        }
    }

    int maxPoints(TPoints& points) {
        if (points.empty()) return 0;
        if (points.size() == 1) return 1;

        TFunctions functions;
        generate_lines(points, functions);
        int max_points = 0; 
        for (const auto& function : functions) {
            max_points = std::max(max_points, static_cast<int>(std::count_if(points.begin(), points.end(), function)));
        }
        return max_points;
    }
};