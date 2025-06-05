class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;
        for_each(nums.begin(), nums.end(), [&mask](int i){mask ^= i;});
        return mask;
    }
};