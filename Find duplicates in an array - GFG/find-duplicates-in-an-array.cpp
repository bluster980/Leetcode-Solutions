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

//adding n everytime to array if element is got value is grater then double of the n then it is repeating.
// class Solution{
//   public:
//     vector<int> duplicates(int arr[], int n) {
//         vector<int> ans;
//         for (int i=0; i<n; i++){
//             int index=arr[i]%n;
//             arr[index]+=n;
//         }
//         for (int i=0; i<n; i++){
//             if((arr[i]/n)>=2)
//                 ans.push_back(i);
//         }
//         if(ans.size()==0)
//             ans.push_back(-1);
//         return ans;
//     }
// };

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