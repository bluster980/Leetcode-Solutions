//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        int l=0,r=n-1;
        int i=0;
        while(i<n){
            if(i > l && nums[i] == 0){
                while(i > l && nums[l] == 0){
                    l++;
                }
                swap(nums[l++],nums[i]);
            }
            else if(i < r && nums[i] == 2){
                while(i < r && nums[r] == 2){
                    r--;
                }
                swap(nums[r--],nums[i]);
            }
            else{
                i++;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends