class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto zerosLeft = std::count(arr.begin(), arr.end(), 0);
        
        for (int i = arr.size()-1; i >= 0; --i) {
            int n = arr[i];
            if (!n) {
                --zerosLeft;
            }
            int dest = i + zerosLeft;
            if (dest >= arr.size())
                continue;
            
            arr[dest] = arr[i];
            if (!n && dest + 1 < arr.size()) {
                arr[dest + 1] = arr[i];
            }
        }
    }
};