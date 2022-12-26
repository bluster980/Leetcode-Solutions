class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0; int i;
        for(i=0; i<nums.size() && i<=ans; i++){
            ans = max(ans, nums[i]+i);
        }
        return i==nums.size();
    }
};