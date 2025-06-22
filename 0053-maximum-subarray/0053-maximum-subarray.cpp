class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0; // should not occur        
        int current_max = nums[0];
        int global_max = current_max;

        // for (int i = 1; i < nums.size(); ++i) {
        //     current_max = std::max(nums[i], current_max + nums[i]);
        //     global_max = std::max(global_max, current_max);
        // }
        for_each(nums.begin()+1, nums.end(),[&current_max, &global_max](int n){
            current_max = std::max(n, current_max + n);
            global_max = std::max(global_max, current_max);
        });
        return global_max;
    }
};