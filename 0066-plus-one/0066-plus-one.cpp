class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int reminder = 1;
        for(auto it = digits.rbegin(); reminder && it != digits.rend(); ++it)
        {
            int sum = *it+reminder;
            if(sum > 9)
            {
                reminder = 1; 
                *it = 0;
            }
            else
            {
                *it = sum;
                reminder = 0;
            }
        }
        if(reminder)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};