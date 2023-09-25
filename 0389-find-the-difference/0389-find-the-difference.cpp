class Solution {
public:
    char findTheDifference(string s, string t) {
        char xx = s[0];
        for(int i=0; i<t.size(); i++){
            xx^=t[i];
        }
        for(int i=1; i<s.size(); i++){
            xx^=s[i];
        }
        return xx;
    }
};