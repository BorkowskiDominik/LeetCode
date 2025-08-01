class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::set<int> maxes;
        for (auto n: nums) {
            maxes.insert(n);
            if (maxes.size() > 3) {
                maxes.erase(*maxes.begin());
            }
        }
        if (maxes.size() < 3)
            return *maxes.rbegin();
        return *maxes.begin();
    }
};