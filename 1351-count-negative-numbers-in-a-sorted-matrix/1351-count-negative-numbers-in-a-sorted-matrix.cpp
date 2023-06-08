class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid[0].size();
        for(int i=0; i<grid.size(); i++){
            int l=0,r=n-1,mid;
            while(l<=r){
                mid = l + (r-l)/2;
                if(grid[i][mid] >= 0){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(l<n && grid[i][l] < 0)
                ans += (n-l); cout<<l<<" "<<r<<endl;
        }
        cout<<endl;
        return ans;
    }
};