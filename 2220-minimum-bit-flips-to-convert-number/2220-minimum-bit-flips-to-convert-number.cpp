class Solution {
public:
    int minBitFlips(int start, int goal) {
        string f="";
        for(int i=0; i<32; i++){
            if(start&(1<<i)){
                f+="1";
            }else{
                f+="0";
            }
        }   
         string s="";
        for(int i=0; i<32; i++){
            if(goal&(1<<i)){
                s+="1";
            }else{
                s+="0";
            }
        }  
        int count=0;
        for(int i=0; i<32; i++){
            if(s[i]!=f[i]){
              count++;
            }
        }
        return count;
    }
};