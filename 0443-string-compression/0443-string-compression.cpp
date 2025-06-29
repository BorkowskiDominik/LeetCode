class Solution {
public:
    int compress(vector<char>& chars) {
        auto in_iter = chars.begin();
        auto search_iter = chars.begin();

        while(search_iter != chars.end()) {
            auto next_pos = std::find_if_not(
                                search_iter,
                                chars.end(),
                                [c = *search_iter](char x){ return x == c; });

            auto length = std::distance(search_iter, next_pos);
            
            *in_iter++ = *search_iter;

            if (length > 1) {
                auto len_str = std::to_string(length);
                in_iter = std::copy(len_str.begin(), len_str.end(), in_iter);
            }            
            search_iter = next_pos;
        }
        return std::distance(chars.begin(), in_iter);
    }
};