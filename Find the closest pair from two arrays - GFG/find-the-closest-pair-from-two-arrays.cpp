//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        if(x>=arr[n-1]+brr[m-1]) return {arr[n-1],brr[m-1]};
        int i=0,j=m-1,dif=INT_MAX;
        vector<int> pr_ans;
        while(j>=0&&i<n){
            if(abs(x-(arr[i]+brr[j]))<dif){
                dif=abs(x-(arr[i]+brr[j]));
                pr_ans={arr[i],brr[j]};
            }
            if(arr[i]+brr[j]<=x){
                i++;
            }
            else{
                j--;
            }
        }
        return pr_ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends