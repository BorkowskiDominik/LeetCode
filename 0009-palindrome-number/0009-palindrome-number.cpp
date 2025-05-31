class Solution {
public:
    // bool isPalindrome_brutal(int x) {
    //     string str = to_string(x);
    //     reverse(str.begin(), str.end());
    //     return to_string(x) == str;
    // }

    bool isPalindrome(int x) {
        string str = to_string(x);
        size_t size = str.size();
        for(int i = 0; i <= size/2; ++i)
        {
            if(str[i] != str[size-1-i])
                return false;
        }
        return true;
    }
};