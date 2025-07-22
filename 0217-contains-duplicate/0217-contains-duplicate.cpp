class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto it = std::unique(nums.begin(), nums.end());
        return it != nums.end();
    }
};