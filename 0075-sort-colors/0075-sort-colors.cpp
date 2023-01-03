class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,i=left,right=nums.size()-1;
        while(i<nums.size() && i<=right){
            if(nums[i] == 0){
                swap(nums[i],nums[left++]); i++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[right--]);
            }
            else{
                i++;
            }
        }
    }
};