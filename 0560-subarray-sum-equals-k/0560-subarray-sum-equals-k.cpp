class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1; // Suma zerowa występuje raz na początku (pusta suma)

        int sum = 0;
        int result = 0;

        for (int num : nums) {
            sum += num;

            // Jeśli istnieje wcześniejszy prefix o sumie sum - k, to taki podciąg istnieje
            if (prefix_count.count(sum - k)) {
                result += prefix_count[sum - k];
            }

            // Zlicz sumę prefixową
            prefix_count[sum]++;
        }

        return result;
    }
};
