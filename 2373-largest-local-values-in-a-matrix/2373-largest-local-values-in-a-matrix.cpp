class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans; int n = grid.size();
        for(int i=0; i<n-2; i++){
            vector<int> temp;
            for(int j=0; j<n-2; j++){
                int maxx = INT_MIN;
                for(int p=i; p<i+3; p++){
                    for(int k=j; k<j+3; k++){
                        maxx = max(maxx, grid[p][k]);
                    }
                }
                temp.push_back(maxx);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};