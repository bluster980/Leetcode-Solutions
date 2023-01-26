//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string x = str;
        sort(x.begin(),x.end());
        int cap = 0;
        for(int i=0; i<x.size(); i++){
            if(str[i]>='A' && str[i]<='Z'){
                cap++;
            }
        }
        // cout<<x<<" "<<cap<<endl;
        string ans;
        int i = 0; int in = 0,ou=cap;
        while(i<str.size()){
            if(str[i]>='A' && str[i]<='Z'){
                ans.push_back(x[in]); in++;
            }
            else{
                ans.push_back(x[ou]); ou++;
            }
            i++;
        }
        return ans;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends