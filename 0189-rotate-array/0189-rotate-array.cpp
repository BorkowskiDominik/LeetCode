class Solution {
public:
    void rotate_cyclic(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // rotation greader than n is equal to (k % n)

        int numElementsMoved = 0;  // how many elements has been already moved

        for (int cycleStartIndex = 0; numElementsMoved < n; ++cycleStartIndex) {
            int currentIndex = cycleStartIndex;
            int valueToMove = nums[cycleStartIndex];

            do {
                int nextIndex = (currentIndex + k) % n;

                // replace value from previous step with the one in destination 
                swap(nums[nextIndex], valueToMove);

                currentIndex = nextIndex;
                ++numElementsMoved;

            } while (cycleStartIndex != currentIndex);  // cycle closed
        }
    }


    // 3 reverse method:
    // Runtime: 0ms (100%) Memory: 29.59MB (~57%)
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

};