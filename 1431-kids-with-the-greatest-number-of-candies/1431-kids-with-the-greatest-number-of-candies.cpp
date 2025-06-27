class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto maxCandies = *std::max_element(candies.begin(), candies.end());
        vector<bool> result(candies.size());

        // std::generate(result.begin(), result.end(), [&, i=0]() mutable {
        //     return candies[i++] + extraCandies >=  maxCandies;
        // });

        std::transform(candies.begin(), candies.end(), result.begin(),
            [=](int c) { return c + extraCandies >= maxCandies; });
        return result;
    }
};