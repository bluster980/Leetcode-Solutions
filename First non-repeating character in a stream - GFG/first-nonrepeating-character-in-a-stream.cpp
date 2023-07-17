//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	struct Compare {
        bool operator()(const pair<int, char>& a, const pair<int, char>& b) const {
            return a.first > b.first; // Compare based on the first element in ascending order
        }
    };
	string FirstNonRepeating(string A){
	    map<char,int> mp; priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> q;
	    string ans;
	    for(int i=0; i<A.size(); i++){
	        q.push({i,A[i]}); mp[A[i]]++;
	        char temp = '#';
            while(!q.empty() && mp[q.top().second] > 1){
                q.pop();
            }
            if(!q.empty()) temp = q.top().second;
            ans.push_back(temp);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends