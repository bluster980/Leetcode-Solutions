class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        if(nums.size() == 1) return {nums[0]};
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = abs(nums[i]-x);
        }
        int l=0,r=nums.size()-1;
        while((r-l) >= k){
            if(mp[nums[l]] <= mp[nums[r]]){
                r--;
            }
            else{
                l++;
            }
        }
        vector<int> ans;
        for(int i=l; i<=r; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};