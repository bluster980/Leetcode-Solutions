//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isPrime(int x){
        int temp = x;
        for(int i=3; i<=x/2; i++){
            if(x%i == 0){
                return temp=i;
            }
        }
        return temp;
    }
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans = {0,1,2};
        for(int i=3; i<=n; i++){
            if(i%2 != 0){
                ans.push_back(isPrime(i));
            }
            else{
                ans.push_back(2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends