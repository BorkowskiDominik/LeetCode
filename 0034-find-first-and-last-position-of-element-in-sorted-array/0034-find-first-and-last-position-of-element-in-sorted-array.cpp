class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }

private:
    int findLeft(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) res = mid;
        }
        return res;
    }

    int findRight(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) res = mid;
        }
        return res;
    }
};
