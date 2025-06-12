class Solution {
public:
    // two pointers approach
    int trap(vector<int>& height) {
        int result{};
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;

        while (left < right) {
            // move pointer that points to lower value -> since it limits volume
            if (height[left] < height[right]) {
                if (height[left] > max_left){
                    // "wall" is highest from the left so far -> no water above it
                    max_left = height[left];
                } else {
                    // if "wall" is lower than max value, add water "above it"
                    result += max_left - height[left];
                }
                left++;
            }
            else {
                if (height[right] > max_right) {
                    // "wall" is highest from the right so far -> no water above it
                    max_right = height[right];
                } else {
                    // if "wall" is lower than max value, add water "above it"
                    result += max_right - height[right];
                }
                right--;
            }
        }

        return result;
    }
};