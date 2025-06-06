class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] > nums[mid + 1])
            right = mid; // peak is on the left half
        else
            left = mid + 1; // peak is on the right half
    }

    return left; // or right, both point to a peak
}

};