class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int level = 0; 

        for (auto g : gain) {
            level += g;
            maxAltitude = std::max(maxAltitude, level);
        }

        return maxAltitude;
    }
};