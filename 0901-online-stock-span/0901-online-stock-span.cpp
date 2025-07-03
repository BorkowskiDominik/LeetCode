class StockSpanner {
    std::stack<std::pair<int, int>, std::vector<std::pair<int, int>>> mono; // {price, span}
public:
    StockSpanner() {
        std::vector<std::pair<int, int>> base;
        base.reserve(10'000);
        mono = decltype(mono)(std::move(base));
    }
    
    int next(int price) {
        int span = 1;
        
        // Consume previous smaller or equal prices
        while (!mono.empty() && mono.top().first <= price) {
            span += mono.top().second;
            mono.pop();
        }
        mono.emplace(price, span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */