class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end()); int maxx = INT_MIN;
        for(int i=nums.size()-1; i>=2; i--){
            int sum = 0;
            // cout<<1<<endl;
            if((nums[i]+nums[i-1] > nums[i-2]) && (nums[i-1]+nums[i-2] > nums[i]) && (nums[i]+nums[i-2] > nums[i-1])){
                sum += (nums[i] + nums[i-1] + nums[i-2]);
            }
            // cout<<sum<<endl;
            maxx = max(sum,maxx);
        }
        return maxx;
    }
};