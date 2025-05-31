class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) 
            return n;

        // slow – miejsce, w które piszemy; zaczynamy od 2,
        // bo pierwsze dwa elementy zostają zawsze
        int slow = 2;

        // fast – iterujemy od trzeciego elementu (i=2)
        for (int fast = 2; fast < n; ++fast) {
            // jeśli nums[fast] różni się od nums[slow-2],
            // to nie jest to trzeci (ani dalszy) duplikat
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
        }
            return slow;
    }

};