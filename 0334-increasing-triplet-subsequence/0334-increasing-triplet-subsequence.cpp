class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        // I remember 2 values, minimal found, and second in sequence
        int first = INT_MAX, second = INT_MAX;
        
        for (auto n : nums) {
            if (n <= first) 
                first = n;
            else if (n <= second)
                second = n;
            else 
                return true;
        }
        return false;
    }
};