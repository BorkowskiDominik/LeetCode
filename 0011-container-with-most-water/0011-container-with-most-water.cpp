class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin(), right = height.end()-1;
        int max_volume = 0;
        while(left < right) {
            int distance = (right - left);
            max_volume = std::max(max_volume, distance * std::min(*left, *right));
            if (*left <= *right)
                ++left;
            else
                --right;
        }
        return max_volume; 
    }
};