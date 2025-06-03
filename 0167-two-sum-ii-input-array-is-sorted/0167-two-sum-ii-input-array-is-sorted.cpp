class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator p1=numbers.begin(), p2 = numbers.end()-1;
    
        while(p1 < p2) {
            int sum = *p1 + *p2;
            if (sum == target)
                break;
            if (sum > target)
                --p2;
            else
                ++p1;
        }

        return {
            static_cast<int>(p1 - numbers.begin()) + 1,
            static_cast<int>(p2 - numbers.begin()) + 1
        };
    }
};