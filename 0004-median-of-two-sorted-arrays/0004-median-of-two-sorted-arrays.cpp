class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t total_size = nums1.size() + nums2.size();
        int med_left_idx = 0, med_right_idx = 0;
        double med_left {}, med_right {};

        if (total_size % 2) {
            med_left_idx = med_right_idx = total_size / 2; // just round down
        } else {
            med_right_idx = total_size / 2; 
            med_left_idx = med_right_idx - 1; 
        }
        auto it1 = nums1.begin(); 
        auto it2 = nums2.begin();
        decltype(it1) current;
        for (int i = 0; i <= med_right_idx; ++i) {
            if (it1 == nums1.end()) {
                current = it2++;
            } else if (it2 == nums2.end()) {
                current = it1++;
            } else {
                if (*it1 < *it2) {
                    current = it1++;
                }
                else {
                    current = it2++;
                }
            }
            if (i == med_left_idx) {
                med_left = *current;
            }
            if (i == med_right_idx) {
                med_right = *current;
            }
        }

        return (med_left + med_right) / 2;
    }
};