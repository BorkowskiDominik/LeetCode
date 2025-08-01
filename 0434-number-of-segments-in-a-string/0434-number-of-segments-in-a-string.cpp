class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        bool was_space = true;
        
        for (char c: s) {
            if (c != ' ' && was_space) {
                segments++;
                was_space = false;
            } else if (c == ' ') {
                was_space = true;
            }

        }
        return segments;
    }
};