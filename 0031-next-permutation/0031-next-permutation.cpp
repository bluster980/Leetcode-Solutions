class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int in = -1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                in = i-1; break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(in>= 0 && nums[i] > nums[in]){
                swap(nums[i],nums[in]); break;
            }
        }
        reverse(nums.begin()+in+1,nums.end());
    }
};