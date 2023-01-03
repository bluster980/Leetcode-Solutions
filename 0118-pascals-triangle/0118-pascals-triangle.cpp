class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; ans.push_back({1});
        int k = 0;
        while(k!=numRows-1){
            vector<int> temp; temp.push_back(1);
            for(int i=0; i<ans[k].size()-1; i++){
                temp.push_back(ans[k][i]+ans[k][i+1]);
            }
            k++;
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};