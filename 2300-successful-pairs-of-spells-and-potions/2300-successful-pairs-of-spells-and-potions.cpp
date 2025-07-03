enum class ALGORITHM {BRUTE, SORTING};
constexpr auto ALGO = ALGORITHM::SORTING;


class Solution {
    using TVI = vector<int>;

    TVI successfulPairsBruteforce(TVI& spells, TVI& potions, long long success);
    TVI successfulPairsSort(TVI& spells, TVI& potions, long long success);

public:
    TVI successfulPairs(TVI& spells, TVI& potions, long long success) { 
        if constexpr(ALGO == ALGORITHM::SORTING)
            return successfulPairsSort(spells, potions, success);

        if constexpr(ALGO == ALGORITHM::BRUTE)
            return successfulPairsBruteforce(spells, potions, success);

        return {};
    }    
};

Solution::TVI Solution::successfulPairsSort(TVI& spells, TVI& potions, long long success) {
    std::sort(potions.begin(), potions.end());
    TVI successful;
    successful.reserve(spells.size());

    for (int spell : spells) {
        auto complement = (success + spell - 1 ) / spell;
        auto it = std::lower_bound(potions.begin(), potions.end(), complement);
        successful.push_back(std::distance(it, potions.end()));
    }

    return successful;
}

Solution::TVI Solution::successfulPairsBruteforce(TVI& spells, TVI& potions, long long success) {
    TVI successful;
    successful.reserve(spells.size());

    for (int i = 0; i < spells.size(); ++i) {
        auto succ = std::count_if(
            potions.begin(),
            potions.end(),
            [spell=spells[i], &success](int p) {
                return static_cast<long long>(p)*spell >= success;
            }
        );
        successful.push_back(succ);
    }
    return successful;
}