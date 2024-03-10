class Solution {
public:
    int minimumLength(string s) {
        int i=0, j = s.size()-1;
        while(i < j){
            // cout<<i<<" "<<j<<endl;
            char temp = s[i];
            if(s[i] != s[j]) break;
            while(i<=j && temp == s[j]){
                j--;
            }
            while(i<=j && temp == s[i]){
                i++;
            }
            // cout<<i<<" "<<j<<endl;
        }
        return j-i+1;
    }
};