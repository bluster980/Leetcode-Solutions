class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1); 
        for(int i=1; i<nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int curr = nums[ans.size()-1];
        for(int i=ans.size()-2; i>=0; i--){
            ans[i] = curr*ans[i];
            curr *= nums[i];
            
        }
        //you can run two for loop and store two dif array then multiple and make ans array it is also right but O(n) space complex...
        return ans;
        
    }
};