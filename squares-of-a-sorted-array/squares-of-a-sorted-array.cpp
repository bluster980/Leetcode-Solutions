class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans; map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]*nums[i]]++;
        }
        for(auto xx:mp){
            for(int i=0; i<xx.second; i++){
                ans.push_back(xx.first);
            }
        }
        return ans;
    }
};