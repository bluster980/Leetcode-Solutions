class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        sort(nums.rbegin(),nums.rend());
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(-1*nums[i])!=mp.end()){
                ans = nums[i]; break;
            }
        }
        return ans;
    }
};