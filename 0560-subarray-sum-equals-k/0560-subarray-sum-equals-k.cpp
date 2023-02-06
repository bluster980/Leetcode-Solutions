class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0]==k;
        map<int,int> mp; mp[nums[0]]++; mp[0]++; 
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        int count = 0; if(nums[0]==k) count++;
        for(int i=1; i<nums.size(); i++){
            if(mp.find(nums[i]-k)!=mp.end()){
                count+=mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};