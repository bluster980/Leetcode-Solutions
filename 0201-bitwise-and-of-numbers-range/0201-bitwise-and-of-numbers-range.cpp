class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int> x(32,0), y(32,0);
        for(int i=0; i<32; i++){
            if(left & (1 << i)) x[i] = 1;
            if(right & (1 << i)) y[i] = 1;
        }
        int ans = 0;
        for(int i=31; i>=0; i--){
            int temp = 0;
            if(y[i] && !x[i]) break;
            else if(x[i] && y[i]){
                temp = temp | (1 << i);
                ans = ans | temp;
            }
        }
        return ans;
    }
};