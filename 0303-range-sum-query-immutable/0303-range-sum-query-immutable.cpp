class NumArray {
    std::vector<int> _sums;

public:
    NumArray(vector<int>& nums) {
        std::swap(_sums, nums);
        for (int i = 1; i < _sums.size(); ++i) {
            _sums[i] += _sums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return _sums[right];
        return _sums[right] - _sums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */