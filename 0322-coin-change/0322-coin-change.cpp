enum class ALGORITHM {RECURSIVE, DP_ARRAY};
constexpr auto ALGO = ALGORITHM::DP_ARRAY;

class Solution {
    int _coinChangeRecursive(const vector<int>& coins, int amount, unordered_map<int, int>& cache) const {
        if (!amount) return 0;
        if (coins.empty() || amount < 0) return -1;

        if (cache.contains(amount)) return cache[amount];
        
        int result = -1;
        for (int i = coins.size()-1; i >= 0; --i) {
            auto change = _coinChangeRecursive(coins, amount-coins[i], cache) + 1;
            if (change > 0) {
                if (result < 0) result = change;
                result = std::min(result, change);
            }
        }        
        cache[amount] = result;
        return cache[amount];
    }

    int _coinChangeDPArray(vector<int>& coins, int amount) const {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
    
        vector<int> dp_array(amount + 1, INT_MAX);
        dp_array[0] = 0;
        int right = 0;
        for (int i = 0; i <= amount; ++i) {
            if (dp_array[i] == INT_MAX) continue;
            for (auto coin: coins) {
                int amount_left = amount - i;
                if (coin > amount_left) continue; // hardening for INT_MAX coin
                auto next = i + coin;
                if (next <= amount) {
                    dp_array[next] = std::min(dp_array[i] + 1, dp_array[next]);
                    right = std::max(right, next);
                }
            }
        }
        return dp_array.back() == INT_MAX ? -1 : dp_array.back();
    }

public:
    int coinChange(vector<int>& coins, int amount) const {
        if constexpr(ALGO == ALGORITHM::RECURSIVE) {
            unordered_map<int, int> cache {};
            return _coinChangeRecursive(coins, amount, cache);
        } else if constexpr(ALGO == ALGORITHM::DP_ARRAY) {
            return _coinChangeDPArray(coins, amount);
        }
        return -1; // algorithm not selected
    }
};