constexpr int ALLOWED_ABSENCES = 1;
constexpr int ALLOWED_CONS_LATES = 2;


class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0;
        int lates = 0;
        
        for (char c : s) {
            if (c == 'L'){
                ++lates;
            } else {
                if (c == 'A')
                    ++absences;
                lates = 0;
            }

            if (absences > ALLOWED_ABSENCES || lates > ALLOWED_CONS_LATES)
                return false;
        }
        return true;
    }
};