class MedianFinder {
    using TVI = std::vector<int>;
    std::priority_queue<int> lower;
    std::priority_queue<int, TVI, std::greater<int>> higher;

public:
    MedianFinder() {
        TVI buf1, buf2;
        buf1.reserve(30000);
        buf2.reserve(30000);
        
        lower = std::priority_queue<int, TVI, std::less<int>>(std::less<int>(), std::move(buf1));
        higher = std::priority_queue<int, TVI, std::greater<int>>(std::greater<int>(), std::move(buf2));
    }

    void addNum(int num) {
        lower.push(num);
        higher.push(lower.top());
        lower.pop();

        if (lower.size() < higher.size()) {
            lower.push(higher.top());
            higher.pop();
        }
    }
    
    inline double findMedian() const {
        if (lower.empty()) return 0.0;
        if (lower.size() == higher.size()) 
            return (lower.top() + higher.top()) / 2.0;
        return lower.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */