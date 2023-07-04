class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(int i=1; i<nums.size(); i++) nums[i]^=nums[i-1];
        return nums.back();
    }
};