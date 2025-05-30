class Solution {
public:

    void print(const vector<int>& v){
        for (const auto& e: v)
            cout << e << " ";
        cout << endl;
    }

    // stl version
    void merge_stl(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums2.begin(), nums2.end(), nums1.begin()+m);
        sort(nums1.begin(), nums1.end());
    }

    // iterator version
    void merge_it(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it_insert = nums1.rbegin();
        auto it_2 = nums2.rbegin();
        auto it_1 = nums1.rbegin() + n;
        while(it_2 != nums2.rend() && it_1 != nums1.rend())
        {
            if(*it_1 > *it_2)
            {
                *it_insert = *it_1;
                ++it_1;
            }
            else
            {
                *it_insert = *it_2;
                ++it_2;
            }
            ++it_insert;
        }
        while(it_2 != nums2.rend())
        {
            *it_insert = *it_2;
            ++it_2;
            ++it_insert;
        }
    }

    // index version
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1,        // last real in nums1
        j = n - 1,        // last in nums2
        k = m + n - 1;    // write position in nums1

        while(i >= 0 && j >= 0) {
            nums1[k--] = (nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]);
        }
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};