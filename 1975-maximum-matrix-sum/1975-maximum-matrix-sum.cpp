class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool cnt=0;
        int mini=100000;
        long long sumi=0;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j:matrix[i]){
                sumi+=abs(j);
                if(j<0)cnt^=1;
                mini=min(mini,abs(j));
            }
        }
        if(cnt)sumi-=2*mini;
        return sumi;
    }
};