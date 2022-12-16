class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0,maxx=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            cur+=nums[i];
            maxx = max(cur,maxx);
            if(cur<0) cur=0;
        }
        return maxx;
    }
};