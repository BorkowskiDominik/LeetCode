struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};

class Solution {
    template<typename T>
    using TVec = vector<T>;

    template<typename T>
    using TVVec = vector<vector<T>>;

    using TPair = std::pair<int, int>;

    static constexpr std::array<TPair, 4> DIRECTIONS {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    static constexpr auto NO_EXIT = -1;
    
    static inline bool isExit(const TVVec<char>& maze, const TPair& p) {
        return p.first == 0 
            || p.first == maze.size()-1
            || p.second == 0 
            || p.second == maze.front().size()-1;
    };

    static inline bool isValidPos(const TVVec<char>& maze, const TPair& p) {
        return p.first >= 0 
            && p.first < maze.size() 
            && p.second >= 0 
            && p.second < maze.front().size()
            && maze[p.first][p.second] == '.';
    };

public:
    int nearestExit(TVVec<char>& maze, TVec<int>& entrance) {
        // unordered_set<std::pair<int, int>, PairHash> visited; // too slow!
        std::queue<TPair> to_visit;
        
        TPair enter = {entrance[0], entrance[1]};
        TPair position = {entrance[0], entrance[1]};
        
        to_visit.push(position);

        int depth = 0;

        while(!to_visit.empty()) {
            size_t level_size = to_visit.size();
            for (int i = 0; i < level_size; ++i) {
                position = to_visit.front(); 
                to_visit.pop();
                if (isExit(maze, position) && position != enter) 
                    return depth;
                
                for (auto dir : DIRECTIONS) {
                    TPair candidate = {position.first + dir.first, position.second + dir.second};
                    if (isValidPos(maze, candidate)) {
                        maze[candidate.first][candidate.second] = '+'; // trick to avoid 'visited' array/set
                        to_visit.push(candidate);
                    }
                }
            }
            ++depth;
        }

        return NO_EXIT;
    }
};