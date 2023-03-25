class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>&no, vector<int>&nI) {
        vector<vector<int>> ans;
        no.push_back(nI);
        sort(no.begin(),no.end());
        for(int i=0; i<no.size(); i++){
            int x = no[i][0],y = no[i][1];
            while(i+1 < no.size() && y >= no[i+1][0]){
                y = max(y,no[i+1][1]);
                i++;
            }
            ans.push_back({x,y});
        }
        return ans;
    }
};