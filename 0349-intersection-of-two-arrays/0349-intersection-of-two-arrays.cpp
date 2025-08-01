class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size())
            return intersection(nums2, nums1);
        
        std::unordered_set<int> v_intersection;
        std::unordered_set<int> used(nums1.begin(), nums1.end());

        for_each(nums2.begin(), nums2.end(), [&v_intersection, &used](int i){
            if (used.contains(i))
                v_intersection.insert(i);
        });

        return std::vector<int>(v_intersection.begin(), v_intersection.end());
    }
};