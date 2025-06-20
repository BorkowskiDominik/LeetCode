template<typename T> 
ostream& operator<<(ostream& o, const std::vector<T>& v) {
    for (const auto& e : v)
        cout << e << " ";
    return o;
}

class Solution {
    using TVI = vector<int>;
    using TVVI = vector<vector<int>>;
public:
    TVI flatten_board(const TVVI& board) {
        TVI flat;
        flat.reserve(board.size() * board.size() + 1);
        flat.push_back(-1); // dummy to simplify indexing

        bool reverse = false;
        for (auto it = board.rbegin(); it != board.rend(); ++it) {
            const auto& row = *it;
            if (reverse)
                flat.insert(flat.end(), row.rbegin(), row.rend());
            else
                flat.insert(flat.end(), row.begin(), row.end());
            reverse = !reverse;
        }
        return flat;
    }


    int bfs(const TVI& flat) {
        int final = flat.size() - 1;
        queue<int> bfs_queue;
        unordered_set<int> visited;
        int counter = 0;

        bfs_queue.push(1);
        visited.insert(1);
        while (!bfs_queue.empty()) {
            int level_size = bfs_queue.size();
            ++counter;
            while (level_size--) {
                int current = bfs_queue.front(); bfs_queue.pop();
                for (int next = current + 1; next <= std::min(current + 6, final); ++next) {
                    int destination = (flat[next] != -1) ? flat[next] : next;
                    if (destination == final) return counter;
                    if (visited.contains(destination)) continue;
                    visited.insert(destination);
                    bfs_queue.push(destination);
                }
            }
        }
        return -1;
    }

    int snakesAndLadders(TVVI& board) {
        auto flat_board = flatten_board(board);
        // cout << flat_board << endl;
        return bfs(flat_board); 
    }
};