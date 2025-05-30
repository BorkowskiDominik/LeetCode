class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto new_end = remove(nums.begin(), nums.end(), val);
        return new_end - nums.begin();
    }
};