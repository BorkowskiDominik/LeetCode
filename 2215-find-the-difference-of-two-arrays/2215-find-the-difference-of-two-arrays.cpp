enum class METHOD {SUPERFAST, UNORDERED_SETS, SETS};

constexpr auto ALGO = METHOD::SUPERFAST;

using TVI = vector<int>;
using TVVI = vector<TVI>;


class Solution {
    TVVI findDifferenceSuperFast(TVI& nums1, TVI& nums2);
    TVVI findDifferenceUnordered(TVI& nums1, TVI& nums2);
    TVVI findDifferenceSets(TVI& nums1, TVI& nums2);

public:
    TVVI findDifference(TVI& nums1, TVI& nums2) {
        if (ALGO == METHOD::SUPERFAST)
            return findDifferenceSuperFast(nums1, nums2);
        else if (ALGO == METHOD::UNORDERED_SETS)
            return findDifferenceUnordered(nums1, nums2);
        else if (ALGO == METHOD::SETS)
            return findDifferenceSets(nums1, nums2);
        return {};
    }
};

TVVI Solution::findDifferenceSuperFast(TVI& nums1, TVI& nums2) {
    constexpr int SHIFT = 1000;
    std::bitset<2001> in1, in2;

    for (int n : nums1) in1.set(n + SHIFT);
    for (int n : nums2) in2.set(n + SHIFT);

    TVI only1, only2;

    for (int i = 0; i < 2001; ++i) {
        if (in1[i] && !in2[i]) only1.push_back(i - SHIFT);
        if (in2[i] && !in1[i]) only2.push_back(i - SHIFT);
    }

    return {only1, only2};
}

TVVI Solution::findDifferenceUnordered(TVI& nums1, TVI& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    
    TVI res1, res2;
    for (int n : s1)
        if (!s2.count(n)) res1.push_back(n);
    for (int n : s2)
        if (!s1.count(n)) res2.push_back(n);

    return {res1, res2};
}

TVVI Solution::findDifferenceSets(TVI& nums1, TVI& nums2) {
    std::set s1(nums1.begin(), nums1.end());
    std::set s2(nums2.begin(), nums2.end());
    
    TVI res1, res2;
    
    std::set_difference(
        s1.begin()
        , s1.end()
        , s2.begin()
        , s2.end()
        , std::inserter(res1, res1.begin()));
    
    std::set_difference(
        s2.begin()
        , s2.end()
        , s1.begin()
        , s1.end()
        , std::inserter(res2, res2.begin()));
    return {res1, res2};
}