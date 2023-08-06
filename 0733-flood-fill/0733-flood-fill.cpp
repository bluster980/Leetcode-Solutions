class Solution {
public:
    void dfs(int i, int j, int n, int m, int color, vector<vector<int>> &ans, vector<vector<int>> &image,int val){
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=val){
            return ;
        }
        // cout<<ans[i][j]<<" ";
        image[i][j] = -1;
        ans[i][j] = color;
        dfs(i,j-1,n,m,color,ans,image,val);
        dfs(i,j+1,n,m,color,ans,image,val);
        dfs(i-1,j,n,m,color,ans,image,val);
        dfs(i+1,j,n,m,color,ans,image,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image; int val = ans[sr][sc];
        dfs(sr,sc,image.size(),image[0].size(),color,ans,image,val);
        return ans;
    }
};