class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1) return 1;
        int result = 0;
        for(int i=1; i<=n; i++){
            int l = numTrees(i-1);
            int r = numTrees(n-i);
            result += l*r;
        }
        return result;
    }
};