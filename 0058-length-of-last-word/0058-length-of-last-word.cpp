class Solution {
public:
    int lengthOfLastWord(string s) {
        int t = s.size()-1;
        while(t>=0 && s[t]==' '){
            t--;
        }
        int count = 0;
        while(t>=0 && s[t]!=' '){
            count++;
            t--;
        }
        return count;
    }
};