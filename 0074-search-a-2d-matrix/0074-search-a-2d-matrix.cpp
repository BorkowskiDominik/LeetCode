class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        //we treat matrix as long 1D array and perform classical binary search
        while (left <= right) {
            int mid = (left + right) / 2;
            int value = matrix[mid / cols][mid % cols];
            if (value == target)
                return true;
            else if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
