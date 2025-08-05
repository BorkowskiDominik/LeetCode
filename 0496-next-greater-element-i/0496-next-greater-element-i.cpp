class Solution {
    template<typename T>
    vector<T>::iterator upper(vector<T>::iterator b, vector<T>::iterator e, T val) {
        while (b < e) {
            if (*b > val)
                return b;
            ++b;
        }
        return e;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.reserve(nums1.size());


        for (int i = 0; i < nums1.size(); ++i) {
            int n = nums1[i];            
            auto searchFrom = std::find(nums2.begin(), nums2.end(), n);
            auto up = upper(searchFrom, nums2.end(), n);
            if (up != nums2.end()) {
                ans.push_back(*up);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};