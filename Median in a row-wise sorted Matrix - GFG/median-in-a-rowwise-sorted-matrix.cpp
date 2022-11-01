//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = 1, high = 2000;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            int small_count = 0; // no of elements less than mid
            int large_count = 0; // no of elements greater than mid
            
            for(int i=0;i<R;i++)
            {
                int ind = lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
                small_count += ind;
                
                ind = lower_bound(matrix[i].begin(), matrix[i].end(), mid+1) - matrix[i].begin();
                
                large_count += (C-ind);
            }
            
            if(small_count <= (R*C)/2 && large_count <= (R*C)/2)
            {
                return mid;
            }
            
            if(small_count > (R*C)/2)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends