class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i]; int maxdig = temp%10;
            while(temp>0){
                maxdig = max(maxdig,temp%10);
                temp/=10;
            }
            mp[maxdig].push_back(nums[i]);
        }
        int maxx = -1;
        for(auto xx:mp){
            auto temp = xx.second;
            sort(temp.begin(),temp.end());
            if(temp.size() > 1){
                maxx = max(temp[temp.size()-1] + temp[temp.size()-2],maxx);
            }
        }
        
        return maxx;
    }
};