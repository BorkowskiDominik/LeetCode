class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> v_intersection;
        std::set_intersection(nums1.begin(), nums1.end(),
                            nums2.begin(), nums2.end(),
                            std::back_inserter(v_intersection));

        return v_intersection;
    }
};