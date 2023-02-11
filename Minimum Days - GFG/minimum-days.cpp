//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        int pairs = 0;
        
        for(int i = 1; i < n; i++) {
            if(s[i-1] == s[i]) pairs++;
        }
        
        if(pairs == 0) return 0;
        // cout<<pairs<<endl;
        for(int i = 0; i < n; i++) {
            
            if(p[i] > 0 && (s[p[i]] == s[p[i]-1])){
                pairs--;
            }
            
            if(p[i] < n-1 && (s[p[i]] == s[p[i]+1])){
                pairs--;
            }
            
            if(pairs <= 0)
                return i+1;
            
            s[p[i]] = '$';
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends