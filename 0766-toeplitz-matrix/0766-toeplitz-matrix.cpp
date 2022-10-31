class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size(); int n = matrix[0].size();
      
      
      
      
      
      
      
        for(int i=1; i<n; i++){
            int j=1; int k = i;
            while(j<m && k<n && matrix[j][k] == matrix[j-1][k-1]){
                k++; j++;
            }
            if(j<m && k<n && matrix[j][k] != matrix[j-1][k-1]) return false;
        }
        for(int i=1; i<m; i++){
            int j=1; int k = i;
            while(k<m && j<n && matrix[k][j] == matrix[k-1][j-1]){
                k++; j++;
            }
            if(k<m && j<n && matrix[k][j] != matrix[k-1][j-1]) return false;
        }
        return true;
    }
};