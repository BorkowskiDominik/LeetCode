class Solution {
public:
    // this implementation uses Boyer–Moore Majority Vote Algorithm
    int majorityElement(vector<int>& nums) {
        int candidate = nums.front();
        size_t counter = 0;

        for (int n : nums)
        {
            if (0==counter)
            {
                candidate = n;
            }
            counter += ( candidate == n ? -1 : 1);
        }
        return candidate;
    }
};