class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique (nums.begin(), nums.end());
        nums = vector<int>(unique.begin(), unique.end());
        return nums.size();
    }
};