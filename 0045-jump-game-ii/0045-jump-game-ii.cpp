class Solution {

template<typename T>
void print(const vector<T>& v) {
    for (const auto & e : v)
        cout << e << " ";
    cout << endl;
}
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;

        int jumps = 0;
        auto it = nums.begin();

        while ( it != nums.end()-1 ) {
            auto next = it+1;
            for (auto t = next; t <= it+*it; ++t) {
                if (t == nums.end())
                    break;

                if (t == nums.end()-1 || next+*next < t+*t){
                    next = t;
                }
            }
            it = next;
            jumps++;
        }

        return jumps;
    }
};