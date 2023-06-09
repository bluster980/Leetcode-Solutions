//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    string ss = S; set<string> st; st.insert(S); vector<string> v;
		    for(int i=0; i<120; i++){
		        next_permutation(S.begin(),S.end());
		        st.insert(S);
		    }
		    for(auto xx:st){
		        v.push_back(xx);
		    }
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends