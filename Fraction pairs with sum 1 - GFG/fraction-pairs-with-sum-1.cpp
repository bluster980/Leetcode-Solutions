//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int x, int n[], int d[])
    {
        for(int i=0; i<x; i++){
            int neu = __gcd(n[i],d[i]);
            n[i] /= neu;
            d[i] /= neu;
        }
        // for(int i=0; i<x; i++) cout<<n[i]<<" ";
        // cout<<endl;
        // for(int i=0; i<x; i++) cout<<d[i]<<" ";
        
        map<pair<int,int>,int> mp; int count = 0;
        for(int i=0; i<x; i++){
            if(mp.find({d[i]-n[i],d[i]}) != mp.end()){
                // cout<<"reached"<<endl;
                count += mp[{d[i]-n[i],d[i]}];
            }
            mp[{n[i],d[i]}]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends