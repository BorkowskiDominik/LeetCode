class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sortujemy po końcach przedziałów rosnąco
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int removed = 0;
        int lastEnd = INT_MIN;

        for (const auto& interval : intervals) {
            if (interval[0] >= lastEnd) {
                lastEnd = interval[1]; // accept
            } else {
                removed++; // delete
            }
        }

        return removed;
    }
};
