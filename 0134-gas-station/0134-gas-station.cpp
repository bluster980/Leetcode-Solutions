class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int temp=0;
        for(int i=0; i<cost.size(); i++){
            temp += gas[i] - cost[i];
        }
        if(temp < 0) return -1;
        int curr=0,start=0;
        for(int i=0; i<gas.size(); i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
        }
        return start;
    }
};