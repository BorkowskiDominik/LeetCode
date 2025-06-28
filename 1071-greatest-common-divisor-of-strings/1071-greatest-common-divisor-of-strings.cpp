template<typename T>
T getGCD(T a, T b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename T>
class DivisorGenerator {
private:
    std::priority_queue<T> _pq;
    T _curr;
    T _a;
    T _b;
public:
    DivisorGenerator(T a, T b): _a(a), _b(b), _curr(getGCD(a, b)) {}
    
    T next() {
        if (_curr == 0) return 0;
        if (_curr == 1) return _curr--;

        T res = _curr;
        for (auto i = _curr - 1 ; i >= 1; --i) {
            if (_a % i || _b % i) continue;
            _curr = i;
            break;
        }
        return res;
    }
};

class Solution {
    static constexpr std::string NO_DIVISOR = "";

public:
    string gcdOfStrings(const string_view& str1, const string_view& str2) {
        auto s1 = str1.size();
        auto s2 = str2.size();
        if (s1 < s2)
            return gcdOfStrings(str2, str1);

        if (!str1.starts_with(str2[0])) return NO_DIVISOR;
        
        DivisorGenerator dg(s1, s2);

        for (auto n = dg.next(); n; n = dg.next()) {
            string_view divisor = str2.substr(0, n);
            bool found = true;
            
            for (int i = 0; i <= std::max(s1, s2) - n; i+=n) {
                if (i < s1&& str1.substr(i, n) != divisor) {
                    found = false;
                    break;
                }
                
                if (i < s2 && str2.substr(i, n) != divisor) {
                    found = false;
                    break;
                }
            }

            if (found)
                return std::string(divisor);
        }

        return NO_DIVISOR;
    }
};