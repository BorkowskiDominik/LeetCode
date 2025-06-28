class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        size_t left = 0, right = 0;
        size_t maxSubarray = 0;
        int k = 1; 

        for (; right < nums.size(); ++right) {
            if (nums[right] == 0) 
                --k;
            if (k < 0) {
                if (nums[left] == 0)
                    ++k;
                ++left;
            }
        }

        return right - left - 1;
    }
};