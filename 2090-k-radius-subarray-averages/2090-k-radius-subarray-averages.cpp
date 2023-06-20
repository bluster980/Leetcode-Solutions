class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1); int x = 0; vector<long long> dumy(nums.size(),-1);
        if(nums.size() < (k*2 + 1)) return ans; dumy[0]=nums[0];
        for(int i=1; i<nums.size(); i++) {dumy[i] = nums[i] + dumy[i-1];}
        ans[k] = dumy[2*k]/(2*k+1);
        for(int j=2*k+1; j<nums.size(); j++){
            ans[k+x+1] = (dumy[j]-dumy[x])/(2*k+1); x++;
        }
        return ans;
    }
};