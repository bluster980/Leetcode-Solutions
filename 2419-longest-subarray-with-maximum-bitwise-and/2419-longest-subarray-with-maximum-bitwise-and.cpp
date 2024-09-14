class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int numsLength = nums.size();
        int r=0, l=0, xr = nums[0];
        int maxLength =0, maxXr= 0;
        
        while(r!=numsLength){
            if(nums[r]>maxXr){
                l = r;
                maxLength = 1;
                maxXr = nums[r];
                xr = nums[r];
            }else
            if((nums[r]&xr)>=xr && xr>=maxXr){
                xr = (nums[r]&xr);
                int len = r - l +1;
                maxLength = max(len,maxLength);
            }else{
                l = r ;
                xr = nums[r];

            }


            r++;
        }

 return maxLength;
    }
};