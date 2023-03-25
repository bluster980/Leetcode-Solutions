class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> t = matrix; int k = matrix[0].size()-1;
        for(int i=0; i<t.size(); i++){
            for(int j=0; j<t[i].size(); j++){
                matrix[i][j] = t[k-j][i];
            }
        }
    }
};