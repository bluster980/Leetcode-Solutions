class Solution {
public:
    int hIndex(vector<int>& nums) {
        int l=0,r = nums.size()-1;
        // if(nums.size() == 1 && nums[0]==0) return 0;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] < nums.size()-mid){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return (nums[l] == 0) ? 0: nums.size()-l;
    }
};