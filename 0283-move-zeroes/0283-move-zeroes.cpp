class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::fill(std::remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }
};