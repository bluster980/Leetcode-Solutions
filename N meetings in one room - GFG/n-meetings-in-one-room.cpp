//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> vp(n);
        for(int i=0; i<n; i++){
            vp[i] = {end[i],start[i]};
        }
        sort(vp.begin(),vp.end());
        // for(int i=0; i<vp.size(); i++){
        //     cout<<vp[i].first<<" "<<vp[i].second<<endl;
        // }
        int in = 0,count=1;
        for(int i=1; i<vp.size(); i++){
            if(vp[in].first < vp[i].second){
                // cout<<vp[i].second<<" "<<vp[i].first<<endl;
                in = i; count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends