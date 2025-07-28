// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int firstBad = n;
        int lastValid = 0;
        while (lastValid + 1 != firstBad) {
            int middle = ( firstBad - lastValid ) / 2 + lastValid;
            if (isBadVersion(middle))
                firstBad = middle;
            else
                lastValid = middle;
        }
        return firstBad;
    }
};