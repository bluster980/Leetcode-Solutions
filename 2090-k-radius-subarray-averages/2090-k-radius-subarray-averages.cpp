class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        if(nums.size() < k*2 + 1) return vector<int> (nums.size(),-1);
        int i=0;
        for(i=0; i<k; i++){
            ans[i] = -1;
            ans[nums.size()-1 - i] = -1;
        }
        // cout<<i<<endl;
        // for(int j=0; j<i; j++){
        //     cout<<j<<" ";
        // }
        long long temp = 0;
        for(int j=0; j<=i+k; j++){
            temp += nums[j];
            // cout<<j<<" ";
        }
        // cout<<temp<<endl;
        ans[i] = temp/(2*k+1); i++;
        while(i < nums.size()-k){
            temp = (temp-nums[i-k-1]+nums[i+k]);
            ans[i] = temp/(2*k+1);
            // cout<<i<<" ";
            i++;
        }
        return ans;
    }
};