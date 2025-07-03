enum class ALGORITHM {BRUTE, MONOTONIC};
constexpr auto ALGO = ALGORITHM::MONOTONIC;


class Solution {
    vector<int> dailyTemperaturesMonotonicStack(vector<int>& temperatures);
    vector<int> dailyTemperaturesBruteForce(vector<int>& temperatures);

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (ALGO == ALGORITHM::BRUTE)
            return dailyTemperaturesBruteForce(temperatures);
        if (ALGO == ALGORITHM::MONOTONIC)
            return dailyTemperaturesMonotonicStack(temperatures);
        return {}; // no algorithm selected
    }
};

vector<int> Solution::dailyTemperaturesMonotonicStack(vector<int>& temperatures) {
    auto temp_size = temperatures.size();
    vector<int> till_warmer(temp_size, 0);
    
    // it could be vector but to pratice semantics I decided to use stack as wrapper
    std::stack<int, vector<int>> mono{std::vector<int>(temp_size)};

    for (int i = 0; i < temp_size; ++i) {
        while (!mono.empty() && temperatures[i] > temperatures[mono.top()]) {
            int idx = mono.top(); mono.pop();
            till_warmer[idx] = i - idx;
        }
        mono.push(i);
    }
    return till_warmer;
}

vector<int> Solution::dailyTemperaturesBruteForce(vector<int>& temperatures) {
    int temp_size = temperatures.size();
    vector<int> warmer(temp_size, 0);

    for (int i = 0; i < temp_size; ++i) {
        auto it_greater = std::find_if(
                temperatures.begin()+i+1,
                temperatures.end(),
                [target = temperatures[i]](int n){return n > target;});

        if (it_greater != temperatures.end())
            warmer[i] = std::distance(temperatures.begin()+i, it_greater);
    }
    return warmer;
}
