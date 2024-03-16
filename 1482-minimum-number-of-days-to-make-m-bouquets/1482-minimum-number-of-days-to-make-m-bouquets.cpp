class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        if(nums.size() < m*1ll*k) return -1;
        int minn = INT_MAX, maxx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        int l = minn, r = maxx;
        while(l <= r){
            int mid = l+(r-l)/2; int temp = 0;
            for(int i=0; i<nums.size(); i++){
                int cnt = 0;
                while(i<nums.size() && nums[i] <= mid){
                    i++; cnt++;
                }
                temp += (cnt/k);
            }
            if(temp >= m) {
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};