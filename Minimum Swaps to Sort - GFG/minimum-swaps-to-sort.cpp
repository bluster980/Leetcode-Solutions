//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&v)
	{
	    vector<int> p = v;
    	sort(p.begin(), p.end());
    	map<int,int> mp;
    	for (int i = 0; i < p.size(); ++i)
    	{
    		mp[p[i]] = i;
    	}
    	int count = 0; int i=0;
    	while(i<v.size()){
    		while(i<v.size() && mp[v[i]] != i){
    			swap(v[mp[v[i]]],v[i]);
    			count++;
    		}
    		i++;
    		
    	}
    	return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends