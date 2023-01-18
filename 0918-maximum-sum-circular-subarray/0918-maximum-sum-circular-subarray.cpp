class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxx = nums[0];
        int minn = -nums[0];
        int curMax = 0;
        int curMin = 0;
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            curMax += nums[i];
            curMin += -nums[i];
            
            if(curMax < nums[i])
                curMax = nums[i];
            if(-nums[i] > curMin)
                curMin = -nums[i];
            
            maxx = max(maxx, curMax);
            minn = max(minn, curMin);
            
        }
        return total + minn == 0 ? maxx : max(total + minn, maxx);
    }
};