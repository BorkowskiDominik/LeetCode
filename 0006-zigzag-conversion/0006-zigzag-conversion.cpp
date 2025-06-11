#include <valarray>

template<typename Iterator>
void print(Iterator b, Iterator e) {
    while(b != e){
        std::cout << *b << " ";
        ++b;
    }
    std::cout << std::endl;
}


class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows < 2 || s.size() == numRows) return s;
        
        std::string result(s.size(), '_');
        int delta = 2*numRows -2;
        int result_index = 0;
        
        for (int i = 0; i < numRows; ++i) {
            int p = i;
            std::optional<int> offset;
            if (i != 0 && i != numRows-1)
                offset = delta - 2*i;

            while (p < s.size()) {
                result[result_index++] = s[p];
                if (offset) {
                    if (p + *offset < s.size()){
                        result[result_index++] = s[p+*offset];
                    }
                }
                p += delta;
            }
        }

        return result;
    }
};