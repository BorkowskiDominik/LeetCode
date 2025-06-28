class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return .0;
        double sum = std::accumulate(nums.begin(), nums.begin()+k, 0);
        double maxSum = sum;
        
        for (auto it = nums.begin() + k; it != nums.end(); ++it) {
            sum = sum - *(it-k) + *it;
            maxSum = std::max(maxSum, sum);
        }
        return maxSum / k;
    }
};