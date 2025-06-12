class Solution {
public:
    using VIter = vector<std::string>::const_iterator;
    std::string merge_line(VIter s, VIter e, int length) {
        int words = std::distance(s, e);
        int letters = std::accumulate(s, e, 0, [](int sum, const std::string& e) {return sum + e.size();});
        int total_spaces = length - letters;    
        if (words == 1) {
            return *s + std::string(total_spaces, ' ');
        }

        int spaces = total_spaces / (words - 1);
        int reminder = total_spaces - spaces * (words - 1);

        std::string line;
        line.reserve(length);
        line += *s;
        ++s;
        while (s != e) {
            line.append(spaces + (reminder ? 1 : 0), ' ');
            line += *s;
            ++s;
            if (reminder)
                reminder--;
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> result;
        auto it_first = words.begin(), it_last = words.begin()+1;

        while(it_first < words.end()) {
            int letters = it_first->size() + 1;
            while (it_last!= words.end() && (letters + it_last->size() <= maxWidth)) {
                letters += it_last->size() + 1;
                it_last++;
            }
            
            // commit line
            if (it_last != words.end()) 
                result.push_back(merge_line(it_first, it_last, maxWidth));
            else { // last line -> no justification
                std::string line {*it_first};
                while (++it_first != it_last) {
                    line += ' ';
                    line += *it_first;
                }
                line += std::string(maxWidth - line.size(), ' ');
                result.push_back(std::move(line));
            }
            it_first = it_last++;
        }
        return result;
    }
};