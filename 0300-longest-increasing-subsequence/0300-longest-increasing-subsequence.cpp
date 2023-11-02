class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        int v[n];
        for(int i=0; i<n; i++) v[i]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    v[i] = max(v[j]+1,v[i]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans,v[i]);
        }
        return ans;
    }
};