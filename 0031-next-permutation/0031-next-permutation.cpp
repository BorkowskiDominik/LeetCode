enum class ALGORITHM {STL, MANUAL};
constexpr auto ALGO = ALGORITHM::MANUAL;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (ALGO ==ALGORITHM::STL)
            return nextPermutationSTL(nums);

        if (ALGO ==ALGORITHM::MANUAL)
            return nextPermutationMANUAL(nums);
    }

    void nextPermutationMANUAL(vector<int>& nums) {
        int n = nums.size();
        int first = -1;

        // 1. Znajdź pierwszy spadek od końca
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                first = i;
                break;
            }
        }

        // 2. Jeśli nie znaleziono — odwróć całość
        if (first == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // 3. Znajdź najmniejszy większy element od nums[first] od końca
        for (int i = n - 1; i > first; --i) {
            if (nums[i] > nums[first]) {
                std::swap(nums[i], nums[first]);
                break;
            }
        }

        // 4. Odwróć suffix
        std::reverse(nums.begin() + first + 1, nums.end());
    }

    void nextPermutationSTL(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};