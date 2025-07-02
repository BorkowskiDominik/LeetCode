class SmallestInfiniteSet {
    int current;
    std::set<int> addedBack;

public:
    SmallestInfiniteSet() : current(1) {}

    int popSmallest() {
        if (!addedBack.empty()) {
            int val = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return val;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current)
            addedBack.insert(num);  // set zabezpiecza przed duplikatami
    }
};
