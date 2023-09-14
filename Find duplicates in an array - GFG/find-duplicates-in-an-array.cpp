//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int nums[], int n) {
        int i=0;
        while(i < n){
            if(nums[i] != nums[nums[i]] && nums[i]!=i){
                swap(nums[i], nums[nums[i]]);
            }
            else{
                i++;
            }
            // for(int k=0; k<n; k++) cout<<nums[k]<<" ";
            // cout<<endl;
        }
        vector<int> ans,temp={-1};
        set<int> st;
        for(int i=0; i<n; i++){
            if(nums[i]!=i){
                st.insert(nums[i]);
            }
        }
        if(st.size()){
            for(auto xx:st){
                ans.push_back(xx);
            }
        }
        return (ans.size() == 0)?temp:ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends