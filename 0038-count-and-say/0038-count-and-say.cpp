class Solution {
    string rle (const string& in) {
        std::vector<std::pair<char, int>> counter;
        // counter.reserve(in.size());
        for (char c : in) {
            if (!counter.empty() && c == counter.back().first)
                counter.back().second++;
            else
                counter.emplace_back(c, 1);
        }

        string out;
        out.reserve(2*in.size());
        for (auto [c, i] : counter) {
            out += to_string(i);
            out += c;
        }
        return out;

        // stringstream buff;
        // for (auto [c, i] : counter) {
        //     buff << i << c;
        // }
        // return buff.str();
    }

public:
    string countAndSay(int n) {
        string result = "1"; 
        if (n == 1) return result;
        while (n-- > 1)
            result = rle(result);

        return result;
    }
};