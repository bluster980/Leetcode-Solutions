class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i=0; i<32; i++){
            int aa = (a & (1<<i)) > 0 ? 1 : 0;
            int bb = (b & (1<<i)) > 0 ? 1 : 0;
            int cc = (c & (1<<i)) > 0 ? 1 : 0;
            int ss = aa | bb;
            // cout<<aa<<" "<<bb<<" "<<cc<<" "<<ss<<endl;
            if(ss != cc){
                if(cc == 1) ans++;
                else if(cc == 0){
                    if(aa == bb) ans+=2;
                    else ans++;
                }
            }
        }
        return ans;
    }
};