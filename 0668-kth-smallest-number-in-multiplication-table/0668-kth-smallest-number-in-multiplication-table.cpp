class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n;
        while(l<r){
            int mid = l+(r-l)/2;
            int cnt = 0;
            for(int i=1; i<=m; i++){
                cnt += min(n, mid/i);
            }
            if(cnt >= k){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};