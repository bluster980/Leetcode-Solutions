class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        if(nums[0] != nums[1]) return nums[0];
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if((mid+1 < nums.size() && mid-1 >= 0 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid-1]){
                    if(mid%2==0){
                        r = mid-1;
                    }
                    else
                        l = mid+1; 
                }
                else if(nums[mid] == nums[mid+1]){
                    if(mid%2==0){
                        l = mid+1; 
                    }
                    else{
                        r = mid-1;
                    }
                    
                }
            }
        }
        return nums[0];
    }
};