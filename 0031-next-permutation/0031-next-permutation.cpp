class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = -1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                temp = i-1; break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(temp>=0 && nums[i] > nums[temp]){
                swap(nums[i],nums[temp]); break;
            }
        }
        reverse(nums.begin()+temp+1,nums.end());
    }
};