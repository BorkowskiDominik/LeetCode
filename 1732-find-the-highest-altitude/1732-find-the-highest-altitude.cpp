class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int level = 0; 

        std::accumulate(gain.begin(), gain.end(), 0, [&maxAltitude](int sum, int e){
            maxAltitude = std::max(maxAltitude, sum+e);
            return sum+e;
        });

        return maxAltitude;

        // manual solution: 
        // for (auto g : gain) {
        //     level += g;
        //     maxAltitude = std::max(maxAltitude, level);
        // }

        // return maxAltitude;
    }
};