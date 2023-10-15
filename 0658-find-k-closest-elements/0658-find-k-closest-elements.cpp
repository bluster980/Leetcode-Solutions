class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int l=0,r=nums.size()-1;
        while((r-l) >= k){
            if(abs(nums[l]-x) <= abs(nums[r]-x)){
                r--;
            }
            else{
                l++;
            }
        }
        return vector<int> (nums.begin()+l,nums.begin()+l+k);
    }
};