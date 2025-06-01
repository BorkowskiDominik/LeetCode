#include <iterator>

class Solution {
public:
    template<typename T>
    void print(vector<T>& nums)
    {
        copy(nums.begin(), nums.end(), ostream_iterator<T, char>(cout, " "));
        cout << endl;
    }
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        // break loop if current index if greater than farthest item we can go
        for (int i = 0; i <= farthest; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1)
                return true;
        }
        return false;
    }
};