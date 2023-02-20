class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {        
        int low=0; int high=nums.size()-1;
        int ans;
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(high>=0 && high<nums.size() && nums[high]==target){
            ans=high;
        }
        else{
            ans=high+1;
        }
        return ans;
    }
};