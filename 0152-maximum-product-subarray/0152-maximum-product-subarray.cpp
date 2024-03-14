class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); int maxx = INT_MIN;
        int curr1 = 1, curr2 = 1;
        for(int i=0; i<n; i++){
            curr1 *= nums[i];
            curr2 *= nums[n-i-1];
            maxx = max(maxx, max(curr1,curr2));
            if(curr1 == 0) curr1 = 1;
            if(curr2 == 0) curr2 = 1;
        }
        return maxx;
    }
};