class Solution {
    std::pair<int, int> expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return {l + 1, r - l - 1}; // start, length
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < s.size(); ++i) {
            auto [l1, len1] = expand(s, i, i);     // odd
            auto [l2, len2] = expand(s, i, i + 1); // even

            if (len1 > max_len) {
                max_len = len1;
                start = l1;
            }
            if (len2 > max_len) {
                max_len = len2;
                start = l2;
            }
        }
        return s.substr(start, max_len);
    }
};
// Manacher's Algorithm
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.empty()) return "";

//         // \U0001f539 Preprocessing: dodajemy znaczniki, by ujednolicić długości parzyste i nieparzyste
//         string t = "^";
//         for (char c : s) {
//             t += "#" + string(1, c);
//         }
//         t += "#$";  // granice

//         int n = t.size();
//         vector<int> P(n, 0); // długości promieni
//         int C = 0, R = 0;     // środek i prawa granica

//         for (int i = 1; i < n - 1; ++i) {
//             int mirror = 2 * C - i;

//             // Jeśli i znajduje się w obrębie prawego palindromu
//             if (i < R) {
//                 P[i] = min(R - i, P[mirror]);
//             }

//             // Próbujemy rozszerzyć palindrom wokół i
//             while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
//                 P[i]++;
//             }

//             // Jeśli palindrom wychodzi poza znany zakres, aktualizujemy C i R
//             if (i + P[i] > R) {
//                 C = i;
//                 R = i + P[i];
//             }
//         }

//         // Znalezienie maksymalnego palindromu
//         int max_len = 0;
//         int center_index = 0;
//         for (int i = 1; i < n - 1; ++i) {
//             if (P[i] > max_len) {
//                 max_len = P[i];
//                 center_index = i;
//             }
//         }

//         // Obliczenie pozycji w oryginalnym stringu s
//         int start = (center_index - max_len) / 2;
//         return s.substr(start, max_len);
//     }
// };
