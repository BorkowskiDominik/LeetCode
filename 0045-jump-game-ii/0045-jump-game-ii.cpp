class Solution {

template<typename T>
void print(const vector<T>& v) {
    for (const auto & e : v)
        cout << e << " ";
    cout << endl;
}
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int currEnd = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                ++jumps;
                currEnd = farthest;
            }
        }

        return jumps;
    }

    int jump_n2(vector<int>& nums) {
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