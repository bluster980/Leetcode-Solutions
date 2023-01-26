class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // cout<<matrix.size();
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][matrix[0].size()-1] >= target){
                int l=0,r=matrix[0].size()-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    // cout<<mid<<endl;
                    if(matrix[i][mid] == target) return true;
                    else if(target < matrix[i][mid]) r=mid-1;
                    else l=mid+1;
                }
            }
        }
        return false;
    }
};