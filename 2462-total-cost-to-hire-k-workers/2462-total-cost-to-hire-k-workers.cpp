enum class ALGORITHM {SINGLE_HEAP, TWO_HEAP};
constexpr auto ALGO = ALGORITHM::TWO_HEAP;


class Solution {
    struct Candidate {
        int cost;
        int index;
        inline bool operator>(const Candidate& other) const {
            return cost == other.cost ? index > other.index : cost > other.cost;
        }
        inline bool operator<(const Candidate& other) const {
            return cost == other.cost ? index < other.index : cost < other.cost;
        }
        inline bool operator<=(const Candidate& other) const {
            return operator<(other) || cost == other.cost && index == other.index;
        }
    };
    using TVCand = std::vector<Candidate>;
    using TQueue = std::priority_queue<Candidate, TVCand, std::greater<>>;
    using TQueueInt = std::priority_queue<int, vector<int>, std::greater<>>;

    long long totalCostSingleHeap(vector<int>& costs, int k, int candidates);
    long long totalCostTwoHeap(vector<int>& costs, int k, int candidates);

public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // most of the time they have similar results around 55ms and 32%
        if constexpr(ALGO == ALGORITHM::SINGLE_HEAP)
            return totalCostSingleHeap(costs, k, candidates); // best : 60.04% (41ms)
            
        if constexpr(ALGO == ALGORITHM::TWO_HEAP)
            return totalCostTwoHeap(costs, k, candidates); // best: 84.55% (35ms)

        return 0;
        // static_assert([](){return false;}, "Algorithm not selected");
    }
};

long long Solution::totalCostTwoHeap(vector<int>& costs, int k, int candidates) {
    auto costs_size = costs.size();
    int left = 0;
    int right = costs_size-1;

    TVCand base1, base2;
    base1.reserve(candidates);
    base2.reserve(candidates);
    TQueue left_heap(std::greater<>(), std::move(base1));
    TQueue right_heap(std::greater<>(), std::move(base2));
    
    for (int i = 0; i < candidates && left <= right; ++i) {
        left_heap.emplace(costs[left], left++);
        if (left <= right)
            right_heap.emplace(costs[right], right--);
    }

    long long totalCost {};

    while(k--) {
        if (right_heap.empty() || (!left_heap.empty() && left_heap.top() <= right_heap.top())) {
            totalCost += left_heap.top().cost; left_heap.pop();
            if (left <= right)
                left_heap.emplace(costs[left], left++);
        } else {
            totalCost += right_heap.top().cost; right_heap.pop();
            if (left <= right)
                right_heap.emplace(costs[right], right--);
        }
    }

    return totalCost;
}

long long Solution::totalCostSingleHeap(vector<int>& costs, int k, int candidates) {
    auto costs_size = costs.size();
    int left = 0;
    int right = costs_size-1;

    TVCand base;
    base.reserve(k + 2* candidates);
    TQueue min_heap(std::greater<>(), std::move(base));

    for (int i = 0; i < candidates && left <= right; ++i) {
        min_heap.emplace(costs[left], left++);
        if (left <= right)
            min_heap.emplace(costs[right], right--);
    }

    long long totalCost {};

    while (k--) {
        auto [cost, index] = min_heap.top(); min_heap.pop();
        totalCost += cost;

        if (left <= right) {
            if (index < left)
                min_heap.emplace(costs[left], left++);
            else
                min_heap.emplace(costs[right], right--);
        }
    }
    return totalCost;
}