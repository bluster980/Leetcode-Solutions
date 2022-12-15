class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int l = i+1,r=nums.size()-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum == target) return sum;
                if(abs(target-sum) < abs(target-ans)){
                    ans = sum;
                }
                if(sum > target){
                    --r;
                }
                else{
                    ++l;
                }
            }
        }
        return ans;
    }
};