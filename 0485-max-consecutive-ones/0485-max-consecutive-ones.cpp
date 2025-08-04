class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCont = 0;
        int current = 0;
        for (auto n : nums) {
            if (n) {
                ++current;
                maxCont = std::max(maxCont, current);
            }
            else
                current = 0;
        }
        return maxCont;
    }
};