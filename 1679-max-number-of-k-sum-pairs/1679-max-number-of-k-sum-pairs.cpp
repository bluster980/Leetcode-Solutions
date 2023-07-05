class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp; int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(k-nums[i])!=mp.end() && mp[k-nums[i]]>0){
                mp[k-nums[i]]--; count++;
            }
            else
                mp[nums[i]]++;
        }
        return count;
    }
};