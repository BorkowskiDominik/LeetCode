class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t total_size = nums1.size() + nums2.size();
        int median_left = 0, median_right = 0;
        double left, right;

        if (total_size % 2) {
            median_left = median_right = total_size / 2; // just round down
        } else {
            median_right = total_size / 2; 
            median_left = median_right - 1; 
        }
        auto it1 = nums1.begin(); 
        auto it2 = nums2.begin();
        decltype(it1) current;
        for (int i = 0; i <= median_right; ++i) {
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
            if (i == median_left) {
                left = *current;
            }
            if (i == median_right) {
                right = *current;
                break;
            }
        }

        return (left + right) / 2;
    }
};