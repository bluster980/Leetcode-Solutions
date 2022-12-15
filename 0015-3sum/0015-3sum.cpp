class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            int l = i+1,r=nums.size()-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(!sum){
                    vector<int> tt = {nums[i],nums[l],nums[r]};
                    ans.push_back(tt);
                    l++;
                    while (l < r && nums[l] == tt[1]) l++;
                    while (l < r && nums[r] == tt[2]) r--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        
        return ans;
    }
};