#include <sstream>

class Solution {
public:
    string intToRoman(int num) {
        static const vector<pair<int, string>> value_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
            {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
            {1,    "I"}
        };
        
        string result;
        for (const auto& [value, symbol] : value_map) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }


    string intToRoman_manual(int num) {
        ostringstream oss; 
        
        // thousands
        int m = num / 1000;
        num = num - 1000 * m;
        oss << std::string(m, 'M');
        
        // hundreds
        int h = num / 100;
        num = num - 100 * h;
        if (h == 9)
            oss << "CM";
        else if (h == 4)
            oss << "CD";
        else {
            if ( h > 4 ) {
                oss << "D";
                h -= 5;
            }            
            oss << std::string(h, 'C');
        }

        // tens
        int t = num / 10;
        num = num - 10 * t;
        if (t == 9)
            oss << "XC";
        else if (t == 4)
            oss << "XL";
        else {
            if ( t > 4 ) {
                oss << "L";
                t -= 5;
            }
            oss << std::string(t, 'X');
        }
        
        if (num == 9)
            oss << "IX";
        else if (num == 4)
            oss << "IV";
        else {
            if ( num > 4 ) {
                oss << "V";
                num -= 5;
            }
            oss << std::string(num, 'I');
        }

        return oss.str();
    }
};