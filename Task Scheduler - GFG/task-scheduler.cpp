//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        map<char,int> mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        map<int,int,greater<int>> mp2;
        for(auto xx:mp){
            mp2[xx.second]++;
        }
        return K*(mp2.begin()->first - 1) + mp2.begin()->first + mp2.begin()->second -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends