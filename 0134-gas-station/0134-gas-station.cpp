class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
    int start = 0;
    int tank = 0;
    int deficit = 0;
    for (int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            deficit += tank;
            start = i + 1;
            tank = 0;
        }
    }
    return tank >= -deficit ? start : -1;
    }
};