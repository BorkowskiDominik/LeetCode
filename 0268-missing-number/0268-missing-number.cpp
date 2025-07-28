class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxNum = nums.size();
        vector<bool> used(maxNum, false);
        for (auto n : nums) {
            used[n] = true;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i])
                return i;
        }
        return maxNum;
    }
};