class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto n_size = nums.size();
        if (k == n_size) return k;
        
        std::queue<int> flipped;
        int maxOnes = k;

        for (int i = 0; i < k; ++i) {
            if (nums[i] == 0) {
                flipped.push(i);
            }
        }

        int left = 0, right = k;
        for (; right < n_size; ++right) {
            if (nums[right] == 0) {
                if (k) {
                    if (flipped.size() == k) {
                        maxOnes = std::max(maxOnes, right - left);
                        left = flipped.front() + 1;
                        flipped.pop();
                    }                
                    flipped.push(right);
                } else {
                    maxOnes = std::max(maxOnes, right - left);
                    left = right + 1;
                }
            }
        }
        maxOnes = std::max(maxOnes, right - left);
        return maxOnes;
    }
};