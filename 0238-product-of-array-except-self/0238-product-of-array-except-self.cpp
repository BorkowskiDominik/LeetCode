class Solution {
    void print(const vector<int>& v) {
        for (const auto& e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
public:
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // 1. Iloczyn prefiksów z lewej
    int left = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = left;
        left *= nums[i];
    }

    // 2. Iloczyn sufiksów z prawej i mnożenie z wynikiem
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= right;
        right *= nums[i];
    }

    return result;
}

};