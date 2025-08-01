class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);  // zaznacz widziane liczby
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                result.push_back(i + 1);  // liczby, które nie zostały oznaczone
        }
        return result;
    }
};
