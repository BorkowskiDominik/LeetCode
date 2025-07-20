class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // Używany jako baza do obliczeń długości
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop(); // zamykający nawias — próbujemy zamknąć coś ze stosu
                if (stk.empty()) {
                    // brak otwierającego nawiasu — nieparzysta sekwencja, ustaw nową bazę
                    stk.push(i);
                } else {
                    // długość aktualnej poprawnej sekwencji
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }

        return maxLen;
    }
};
