constexpr std::array<char, 16> MAP {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0"; // Handle zero case
        
        string out;
        uint32_t n = static_cast<uint32_t>(num); // Treat as unsigned 32-bit integer
        
        while (n) {
            out.push_back(MAP[n % 16]); // Get hex digit
            n /= 16;                    // Shift right by 4 bits
        }
        
        reverse(out.begin(), out.end()); // Reverse to get correct order
        return out;
    }
};