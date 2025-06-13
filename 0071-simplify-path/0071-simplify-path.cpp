class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> path_stack{};
        
        int word_beg = path.find_first_not_of('/', 0);
        int word_end = path.find('/', word_beg);
        
        while (word_beg != std::string::npos) {
            std::string word = path.substr(word_beg, word_end - word_beg);
            
            if (word == "..") {
                if(!path_stack.empty()) 
                    path_stack.pop_back(); 
            }
            else if (word != "."){
                path_stack.push_back(word);
            }
            
            word_beg = path.find_first_not_of('/', word_end);
            word_end = path.find('/', word_beg);
        }

        if (path_stack.empty())
            return "/";
        std::string result;
        result.reserve(
            std::accumulate(
                path_stack.begin()
                , path_stack.end()
                , 0
                , [](int sum, const std::string& s){return sum + s.size();}
            )
            + path_stack.size()
        );
        for (auto& s : path_stack) {
            result += '/';
            result += std::move(s);
        }

        return result;
    }
};