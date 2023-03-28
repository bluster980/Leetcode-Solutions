class Solution {
public:
    bool judgeCircle(string m) {
        int uu=0,dd=0,ll=0,rr=0;
        for(int i=0; i<m.size(); i++){
            if(m[i]=='U') uu++;
            if(m[i]=='D') dd++;
            if(m[i]=='L') ll++;
            if(m[i]=='R') rr++;
        }
        return (uu==dd)&&(ll==rr);
    }
};