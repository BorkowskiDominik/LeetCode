class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums.front();
        int maxProd = nums.front();
        int result = nums.front();

        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];

            if (n < 0)
                std::swap(maxProd, minProd);
            
            maxProd = std::max(n, maxProd * n);
            minProd = std::min(n, minProd * n);
            
            result = std::max(result, maxProd);
        }

        return result;
    }
};