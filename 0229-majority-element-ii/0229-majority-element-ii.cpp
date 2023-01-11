class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> v;
        for(auto xx:mp){
            if(xx.second > floor(nums.size()/3.0)){
                v.push_back(xx.first);
            }
        }
        return v;
    }
};