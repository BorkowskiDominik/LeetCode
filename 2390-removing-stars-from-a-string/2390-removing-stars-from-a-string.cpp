class Solution {
public:
    string removeStars(string s) {
        std::string result;
        result.reserve(s.size());

        for (char c: s) {
            if (c == '*')
                result.pop_back();
            else
                result.push_back(c);
        }
        return result;
    }
};

// class Solution {
// public:
//     string removeStars(string s) {
//         std::stack<char> stck;
//         for (char c: s) {
//             if (c == '*')
//                 stck.pop();
//             else
//                 stck.push(c);
//         }
//         std::string result(stck.size(), '\0');
//         for (int i = stck.size()-1; i >= 0; --i) {
//             result[i] = stck.top();
//             stck.pop();
//         }
//         return result;
//     }
// };