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
            TvInt& result_back = result.back();
            if (intervals[i][0] <= result_back[1]) {
                result_back[1] = std::max(intervals[i][1], result_back[1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};