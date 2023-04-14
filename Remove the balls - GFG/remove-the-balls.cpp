//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> c, vector<int> r){
        stack<pair<int,int>> st;
        if(n==1)
         return 1;
         
         st.push({c[0],r[0]});
        int i=1;
        while(i<n){
            if(!st.empty()){
                auto it = st.top();
                int col = it.first;
                int rad  = it.second;
                 if(r[i]==rad && c[i]==col){
                      st.pop();
                 }
                 else{
                   st.push({c[i],r[i]});
                  }
            }
            else{
                 st.push({c[i],r[i]});

            }
            i++;
        }
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends