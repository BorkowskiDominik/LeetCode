class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = totalSum;

        for (int i = 0; i < nums.size(); ++i) {
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};