class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n_cities = isConnected.size();
        if (n_cities == 1) return 1;

        int provinces = 0;
        std::vector<bool> visited(n_cities, false);
        std::vector<int> to_visit;
        to_visit.reserve(n_cities);

        while(!std::all_of(visited.begin(), visited.end(), std::identity{}))
        {
            ++provinces;
            auto it = std::find_if(visited.begin(), visited.end(), [](bool b){ return !b;});
            to_visit.push_back(std::distance(visited.begin(), it));
            while (!to_visit.empty()) {
                auto current = to_visit.back(); // to avoid vector relocation, I will use it like stack
                to_visit.pop_back();
                for (int i = 0; i < n_cities; ++i) {
                    if (isConnected[current][i] && !visited[i]) {
                        visited[i] = true;
                        to_visit.push_back(i);
                    }
                }
            }            
        }
        return provinces;
    }
};