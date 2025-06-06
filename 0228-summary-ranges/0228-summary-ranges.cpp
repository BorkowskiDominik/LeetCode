class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty())
            return result;

        int range_start = nums.front();
        auto format_range = [&](int a, int b){
            return (a == b) ? to_string(a) : to_string(a) + "->" + to_string(b);
        };
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] +1 != nums[i]){
                result.push_back(format_range(range_start, nums[i-1]));
                range_start = nums[i];          
            }
        }
        result.push_back(format_range(range_start, nums.back()));
        return result;
    }
};