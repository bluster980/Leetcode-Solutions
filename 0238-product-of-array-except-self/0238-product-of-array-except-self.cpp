class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1); 
        vector<int> first(nums.size(),1),second(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            first[i] = first[i-1] * nums[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            second[i] = second[i+1] * nums[i+1];
        }
        for(int i=0; i<nums.size(); i++){
            ans[i] = second[i]*first[i];
        }
        return ans;
        
    }
};