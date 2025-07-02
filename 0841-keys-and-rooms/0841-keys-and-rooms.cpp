class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n_rooms = rooms.size();
        vector<bool> visited(n_rooms, false);
        int n_visited = 0;
        std::queue<int> keys;
        keys.push(0);
        visited[0] = true;

        for (; !keys.empty(); keys.pop()) {
            auto key = keys.front();
            ++n_visited;
            for (auto new_key : rooms[key]) {
                if (!visited[new_key]) {
                    keys.push(new_key);
                    visited[new_key] = true;
                }
            }

        }
        return n_visited == n_rooms;
    }
};