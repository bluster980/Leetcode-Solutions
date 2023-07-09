//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    {
        int i=0;
        while(i < n){
            // cout<<i<<" ";
            if(nums[i]<=n && nums[i]>0 && (nums[i]!=nums[nums[i]-1])){
                swap(nums[i],nums[nums[i]-1]);
            }
            else i++;
            // if(nums[i]>n || nums[i]<0 || (nums[i] == nums[nums[i]-1])) i++;
        }
        // for(int i=0; i<n; i++) cout<<nums[i]<<" ";
        int x = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < x) continue;
            if(nums[i] == x) x++;
            else break;
        }
        return x;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends