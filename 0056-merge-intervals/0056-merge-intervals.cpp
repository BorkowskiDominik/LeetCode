class Solution {
    using TvInt = vector<int>;
    using TvvInt = vector<TvInt>;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;
        
        TvvInt result;
        sort(intervals.begin(), intervals.end(), [](TvInt& a, TvInt& b) {return a[0] < b[0];});
        
        result.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); ++i) {
            TvInt& last = result.back();
            TvInt& current = intervals[i];

            if (current[0] <= last[1])
                last[1] = std::max(current[1], last[1]);
            else
                result.push_back(current);
        }
        return result;
    }
};