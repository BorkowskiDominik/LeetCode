#include <iterator>

class Solution {
public:
    template<typename T>
    void print(const vector<T>& v)
    {
        copy(v.begin(), v.end(), ostream_iterator<T, char>(cout, " "));
        cout << endl;
    }

    // DP array version
    int rob_arr(vector<int>& nums) {
        vector<int> profits(nums.size()+3, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            profits[i+2] = std::max(nums[i] + profits[i], profits[i+2]);
            profits[i+3] = std::max(nums[i] + profits[i], profits[i+3]);
        }
        return std::max(*(profits.end()-1), *(profits.end()-2));
    }

    int rob(vector<int>& nums) {
        int prev = 0;    // dp[i - 1]
        int prev2 = 0;   // dp[i - 2]
        for (int num : nums) {
            int current = std::max(prev, num + prev2);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
};