class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i=0; i<nums.size(); i++){
            k=i;
            if(nums[i]==0){
                while(k < nums.size()-1 && nums[k]==0) {k++;}
                swap(nums[i],nums[k]);
            }
        }
    }
};