class Solution {
public:
    int lengthOfLastWord_manual(string s) {
        int i = s.size() - 1;

        // skip tailing spaces
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        int length = 0;

        // calculate lenght of word
        while (i >= 0 && s[i] != ' ') {
            --i;
            ++length;
        }

        return length;
    }

    int lengthOfLastWord(const string& s) {
        auto it = find_if(s.rbegin(), s.rend(), [](char c) { return c != ' '; });
        auto end = find_if(it, s.rend(), [](char c) { return c == ' '; });
        return distance(it, end);
    }
    
    int lengthOfLastWord_STL(string s) {
        reverse(s.begin(), s.end());
        istringstream is(s);
        string w;
        is >> w;
        return w.size();
    }
};