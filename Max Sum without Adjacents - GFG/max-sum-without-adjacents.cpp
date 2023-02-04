//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *v, int n) {
	    vector<int> dp(n); if(n==1) return v[0]; if(n==2) return max(v[0],v[1]);
        int temp = max(v[0],v[1]);
        dp[0]=v[0], dp[1]=v[1], dp[2]=v[2]+v[0];
        for(int i=3; i<n; i++){
            dp[i] = (max(dp[i-2], dp[i-3]) + v[i]);
        }
        return max(dp[n-1],dp[n-2]);
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