class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxx = nums[0]; int in = 0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i]>nums[i+1]){
                if(nums[i] > maxx){
                    in = i;
                    maxx = nums[i];
                }
            }
        }
        if(nums[nums.size()-1] > maxx){
            in = nums.size()-1;
            maxx = nums[in];
        }
        return in;
    }
};