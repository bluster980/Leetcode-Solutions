class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0,j=0,maxx=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) zero++;
            if(zero > 1){
                if(nums[j]==0) zero--;
                j++;
            }
            maxx=max(maxx,i-j);
            // cout<<j<<" "<<i<<endl;
        }
        return (maxx==nums.size())?maxx-1:maxx;
    }
};