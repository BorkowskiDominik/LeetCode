class RecentCounter {
    std::vector<int> data;
    size_t start = 0;

public:
    RecentCounter() {
        data.reserve(10000); // może być więcej
    }

    int ping(int t) {
        data.push_back(t);
        while (data[start] < t - 3000)
            ++start;
        return data.size() - start;
    }
};
