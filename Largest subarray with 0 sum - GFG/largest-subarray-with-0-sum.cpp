//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int> mp; mp[A[0]] = 0; mp[0]=-1;
        for(int i=1; i<A.size(); i++){
            A[i]+=A[i-1];
            if(mp.find(A[i])==mp.end()){
                mp[A[i]] = i;
            }
        }
        int maxx = 0;
        for(int i=0; i<A.size(); i++){
            if(mp[A[i]]!=i){
                maxx = max(maxx,i-mp[A[i]]);
            }
        }
        return maxx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends