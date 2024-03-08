class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp; int maxx = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            maxx = max(maxx, mp[nums[i]]);
        }
        int cnt = 0;
        for(auto xx:mp){
            if(xx.second == maxx){
                cnt += xx.second;
            }
        }
        return cnt;
    }
};