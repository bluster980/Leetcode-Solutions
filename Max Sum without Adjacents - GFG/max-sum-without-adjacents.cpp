//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *v, int n) {
	    vector<int> dp(n+10);
	    int ix = 0;
	    int mx = 0;
	    for(int i=3; i<n+3; ++i)
	    {
	        int x = 
	        dp[i] = max(dp[i],v[ix]+dp[i-2]);
	        dp[i] = max(dp[i],v[ix]+dp[i-3]);
	        ix++;
	        mx = max(mx,dp[i]);
	    }
	    
	    return mx;
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends