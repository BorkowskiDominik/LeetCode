class Solution {
    template<typename T>
    void print(const vector<T>& v) {
        for (auto const& e : v)
            cout << e << " ";
        cout << endl;
    }
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        if (ratings.size() == 2) return ratings[0] == ratings[1] ? 2 : 3;

        std::vector<int> candies(ratings.size(), 1);

        candies[0] = 1;
        for (int r = 1; r < ratings.size(); r++) {
            if (ratings[r] > ratings[r-1])
                candies[r] = candies[r-1] + 1;
        }

        for (int r = ratings.size()-2; r >= 0; r--) {
            if (ratings[r] > ratings[r+1])
                candies[r] = std::max(candies[r], candies[r+1]+1);
        }
        return std::reduce(candies.begin(), candies.end());
    }
};