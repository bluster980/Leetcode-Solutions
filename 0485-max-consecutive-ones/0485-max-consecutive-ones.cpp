class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, sum = 0, ans = INT_MIN; nums.push_back(0);
        for(int i=0; i<nums.size(); i++){
            if(!nums[i]){
                ans = max(count,ans);
                count = 0;
            }
            else{
                count++;
            }
        }
        return ans;
    }
};