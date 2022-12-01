class Solution {
public:
    bool halvesAreAlike(string s) {
        if(s.size()%2!=0) return 0;
        int count = 0;
        int count2 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                count++;
                if(i<s.size()/2){
                    count2++;
                }
            }
        }
        if(count2*2 == count){
            return 1;
        }
        return 0;
    }
};