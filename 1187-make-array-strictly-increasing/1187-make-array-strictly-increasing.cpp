class Solution {
private:
    int solver(vector<int>& arr1, vector<int>& arr2, int prev, int curr, bool flag, int dp[][2001][2]){
        if(curr == arr1.size()) return 0;

        //prev == -1 is the main problem so thats why shift the index
        if(dp[prev+1][curr][flag] != -1) return dp[prev+1][curr][flag];

        int element = prev==-1 ? -1 : (flag ? arr2[prev] : arr1[prev]);

        int skip = 1e9 + 1;
        if(arr1[curr] > element){
            skip = solver(arr1,arr2,curr,curr+1,0,dp);
        }

        int index = upper_bound(arr2.begin(), arr2.end(), element) - arr2.begin();
        int pick = 1e9 + 1;

        if(index != arr2.size()){
            pick = 1 + solver(arr1,arr2,index,curr+1,1,dp);
        }

        return dp[prev+1][curr][flag] = min(pick,skip);

    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());

        int dp[2003][2001][2];
        memset(dp,-1,sizeof(dp));

        int ans = solver(arr1,arr2,-1,0,0,dp);
        return ans==1e9+1 ? -1 : ans;
    }
};