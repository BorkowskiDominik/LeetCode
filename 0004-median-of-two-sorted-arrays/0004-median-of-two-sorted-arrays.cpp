enum class ALGORITHM {LINEAR, OPTIMAL};
constexpr auto ALGO = ALGORITHM::OPTIMAL;

class Solution {
    double findMedianSortedArraysLinear(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArraysBinarySearch(vector<int>& nums1, vector<int>& nums2);

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if constexpr(ALGO == ALGORITHM::LINEAR)
            return findMedianSortedArraysLinear(nums1, nums2); // Complexity: O(n + m)
        else if constexpr(ALGO == ALGORITHM::OPTIMAL)
            return findMedianSortedArraysBinarySearch(nums1, nums2); // Complexity : O (log(min(m, n)))
        else
            return 0.0;
    }
};

double Solution::findMedianSortedArraysBinarySearch(vector<int>& A, vector<int>& B) {
    if (A.size() > B.size()) return findMedianSortedArraysBinarySearch(B, A); // A jest krótsza

        int m = A.size();
        int n = B.size();
        int half_len = (m + n + 1) / 2;
        int imin = 0, imax = m;

        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;

            if (i < m && B[j - 1] > A[i]) {
                // i za małe, przesuwamy w prawo
                imin = i + 1;
            } else if (i > 0 && A[i - 1] > B[j]) {
                // i za duże, przesuwamy w lewo
                imax = i - 1;
            } else {
                // i jest idealne
                int max_of_left = 0;
                if (i == 0) max_of_left = B[j - 1];
                else if (j == 0) max_of_left = A[i - 1];
                else max_of_left = std::max(A[i - 1], B[j - 1]);

                if ((m + n) % 2 == 1)
                    return max_of_left;

                int min_of_right = 0;
                if (i == m) min_of_right = B[j];
                else if (j == n) min_of_right = A[i];
                else min_of_right = std::min(A[i], B[j]);

                return (max_of_left + min_of_right) / 2.0;
            }
        }
    return 0.0;
}

// Complexity: O(n + m)
double Solution::findMedianSortedArraysLinear(vector<int>& nums1, vector<int>& nums2) {
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
        if (it1 == nums1.end())        current = it2++;
        else if (it2 == nums2.end())   current = it1++;
        else {
            if (*it1 < *it2) current = it1++;
            else             current = it2++;
        }
        if (i == med_left_idx)  med_left = *current;
        if (i == med_right_idx) med_right = *current;
    }

    return (med_left + med_right) / 2;
}
