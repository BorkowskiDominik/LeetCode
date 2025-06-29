class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        stack.reserve(asteroids.size());

        for (auto a : asteroids) {
            if (a > 0) {
                stack.push_back(a);
            } else {
                bool destroyed = false;
                while (!stack.empty() && stack.back() > 0) {
                    auto back = stack.back();
                    if (back < std::abs(a)) {
                        stack.pop_back();
                    } else {
                        if (back == std::abs(a))
                            stack.pop_back();
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed) {
                    stack.push_back(a);
                }
            }
        }
        return stack;
    }
};