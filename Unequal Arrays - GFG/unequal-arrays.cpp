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
    long long solve(int n, vector<int> &a, vector<int> &b) {
        long long sum = 0, ans = -1, cnt = 0;
        vector<int> odd, even;
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        
        for(int i = 0; i < n; i++) {
            if(b[i]&1) odd.push_back(b[i]);
            else even.push_back(b[i]);
        }
        
        int x = (int)odd.size() - 1, y = (int)even.size() - 1;
        for(int i = n-1; i >= 0; i--) {
            if(a[i]&1) {
                if(x < 0) return ans;
                sum += (a[i] - odd[x])/2;
                cnt += max(0, (a[i]-odd[x])/2), x--;
            }
            else {
                if(y < 0) return ans;
                sum += (a[i] - even[y])/2;
                cnt += max(0, (a[i]-even[y])/2), y--;
            }
        }
        if(sum != 0) return ans;
        return cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends