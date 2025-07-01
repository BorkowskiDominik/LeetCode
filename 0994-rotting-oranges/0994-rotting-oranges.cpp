class Solution {    
    struct Position {
        int x;
        int y;
    };

    static constexpr std::array<Position, 4> DIRECTIONS {{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
    
    std::pair<int, std::queue<Position>> initQueue(const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int fresh {};
        
        std::queue<Position> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j){
                switch (grid[i][j]) {
                    case 1: // fresh
                        ++fresh;
                        break;
                    case 2: // rotten
                        q.emplace(i,j);
                        break;
                }         
            }
        }
        return {fresh, q};
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int minutes {-1};
        
        auto [fresh, q] = initQueue(grid);
        
        if (!fresh) 
            return 0;
        
        auto isValidCandidate = [&grid, &rows, &cols](const Position& p){
            return p.x >= 0 && p.y >= 0 && p.x < rows && p.y < cols && grid[p.x][p.y] == 1;
        };

        while(!q.empty()) {
            ++minutes;
            auto level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                auto [x, y] = q.front(); q.pop();
                for (Position dir : DIRECTIONS) {
                    Position candidate {x + dir.x, y + dir.y};
                    if (isValidCandidate(candidate)) {
                        grid[candidate.x][candidate.y] = 2;
                        if (fresh) {
                            q.push(candidate);
                            --fresh;
                        }
                    }
                }
            }
        }

        return fresh ? -1 : minutes;
    }
};