class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0; unordered_map<int,int> mp; int maxx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum--;
            else sum++;
            if(sum == 0) maxx = max(maxx, i+1);
            else{
                if(mp.find(sum) != mp.end()){
                    maxx = max(maxx, i-mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        return maxx;
    }
};