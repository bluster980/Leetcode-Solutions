class Solution {
public:
    int findComplement(int num) {
        string x,ans; int fin = 0;
        for(int i=0; i<32; i++){
            x.push_back((((1<<i) & num)?1:0) + '0');
        }
        int i=x.size()-1;
        while(x[i]=='0'){
            i--;
        }
        for(;i>=0;i--){
            if(x[i]=='1') ans.push_back('0');
            else ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        // cout<<ans<<endl; 
        long long xx = 1;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]=='1'){
                fin += xx;
            }
            xx*=2;
        }
        return fin;
    }
};