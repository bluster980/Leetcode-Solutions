class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(rowIndex==0) return ans[0];
        ans.push_back({1,1});
        if(rowIndex==1) return ans[1];
        else{
            for(int i=2; i<=rowIndex; i++){
                vector<int> v;
                v.push_back(1);
                for(int j=0; j<ans[i-1].size()-1;j++){
                    v.push_back(ans[i-1][j]+ans[i-1][j+1]);
                }
                v.push_back(1);
                ans.push_back(v);
            }
        }
        return ans[rowIndex];
    }
};