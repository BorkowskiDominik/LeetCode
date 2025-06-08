class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total_gas += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return total_gas < 0 ? -1 : start;
    }
};
