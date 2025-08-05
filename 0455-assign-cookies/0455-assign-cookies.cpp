class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        auto child = g.begin();
        auto cookie = std::lower_bound(s.begin(), s.end(), *child);

        while (child != g.end() && cookie != s.end()) {
            if (*cookie >= *child) {
                ++child;
            }
            ++cookie;
        }

        return std::distance(g.begin(), child);
    }
};
