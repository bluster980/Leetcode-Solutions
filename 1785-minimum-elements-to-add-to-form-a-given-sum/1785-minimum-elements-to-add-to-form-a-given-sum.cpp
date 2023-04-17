class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long summ = 0;
        for(int i=0; i<nums.size(); i++){
            summ+=nums[i];
        }
        long long cnt = 0, tmp = goal-summ;
        goal = abs(goal);
        tmp = abs(tmp);
        if(tmp > limit){
            cnt += tmp/limit;
            if(tmp%limit!=0) cnt++;
        }
        else cnt++;
        if(summ == goal) return 0;
        return cnt;
    }
};