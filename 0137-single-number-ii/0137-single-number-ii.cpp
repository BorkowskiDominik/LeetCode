class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            int bit_sum = 0;
            for (int num : nums)
                bit_sum += (num >> i) & 1;

            if (bit_sum % 3 != 0)
                result |= (1 << i);
        }

        // Obsługa liczb ujemnych (dla 32-bitowego inta)
        return result;
    }
};
