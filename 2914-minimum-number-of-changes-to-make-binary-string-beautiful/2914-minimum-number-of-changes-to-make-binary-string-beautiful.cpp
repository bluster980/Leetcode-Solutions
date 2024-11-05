class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        int len = s.size() % 2 == 0 ? s.size() : s.size() + 1;
        for(int i=0; i < len; i+=2){
            if(s[i]!=s[i+1]) cnt++; 
        }
        return cnt;
    }
};