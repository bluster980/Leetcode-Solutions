//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        int count = 0;
        if(n==0) return true;
        vector<int>arr(seats);
        
        for(int i=0;i<m;i++){
            if(i==0 && arr[i]==0 && arr[i+1] == 0){
                arr[i] = 1;
                count++;
            }else if(i==m-1 && arr[i]==0 && arr[i-1] == 0){
                arr[i] = 1;
                count++;
            }
            else if(i>0 && i<m-1 && arr[i]==0 && arr[i-1] == 0 && arr[i+1] ==0){
                arr[i]=1;
                count++;
            }
            if(count==n) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends