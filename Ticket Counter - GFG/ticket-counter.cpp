//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int res=N/K;
        if(res%2==0) 
        {
            if(N%K==0) return K*(res/2)+1;
            else return K*(res/2)+N%K;
        }
        else 
        {
            if(N%K==0) return N-K*(res/2);
            else return 1+N-(K*(res/2) +N%K);
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends