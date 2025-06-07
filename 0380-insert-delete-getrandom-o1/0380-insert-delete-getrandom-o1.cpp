#include <random>

class RandomizedSet {
    std::unordered_map<int,int> _map;
    std::vector<int> _numbers;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (_map.contains(val))
            return false;
        _numbers.push_back(val);
        _map[val] = _numbers.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!_map.contains(val))
            return false;

        int index = _map[val];
        int last = _numbers.back();

        std::swap(_numbers[index], _numbers.back());
        _numbers.pop_back();
        
        _map[last] = index;  // aktualizacja indeksu ostatniego elementu
        _map.erase(val);
        return true;
    }
    
    int getRandom() {
        static std::mt19937 gen(std::random_device{}());  // utrzymujemy generator jako static
        std::uniform_int_distribution<> dist(0, _numbers.size() - 1);
        return _numbers[dist(gen)];
    }


};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */