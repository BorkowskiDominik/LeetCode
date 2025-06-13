class Solution {
    void print(vector<vector<int>>& points) {
        for (const auto& v : points) {
            cout << "[" << v[0] << " , " << v[1] << "]" << endl;
        }
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b){return a[1] < b[1];});

        int counter = {};
        auto it = points.begin();
        while(it != points.end()) {
            counter++;
            int arrow = (*it)[1];
            auto next = std::find_if(
                it,
                points.end(),
                [arrow](const auto& ballon) {return ballon[0] > arrow;}
            );
            it = next;
        }

        return counter;
    }

    int findMinArrowShots_with_removal(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b){return a[1] < b[1];});
        // Very strange!
        // If we use copies in sort (auto instead of const auto&)
        // std::sort(points.begin(), points.end(), [](auto a, auto b){return a[1] < b[1];});
        int counter = {};

        while(!points.empty()) {
            counter++;
            int arrow = points[0][1];
            auto it = std::find_if(
                points.begin(),
                points.end(),
                [arrow](const auto& ballon) {return ballon[0] > arrow;}
            );
            points.erase(points.begin(), it);
        }

        return counter;
    }
};