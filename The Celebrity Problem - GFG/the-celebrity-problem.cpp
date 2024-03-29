//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>&nums, int n) 
    {
        unordered_map<int,int> mp;
        int xx = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int temp = 0;
            for(int j=0; j<nums[i].size(); j++){
                temp += nums[i][j];
                if(nums[i][j]){
                    mp[j]++;
                }
            }
            if(!temp){
                if(xx==INT_MAX){
                    xx = i;
                }
                else{
                    return -1;
                }
            }
            
        }
        if(mp[xx] == nums.size()-1){
            return xx;
        }
        return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends