class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0;
        int j = s.size()-1;
        while(s[i]==s[j] && i!=j && i<j){
            i++; j--;
        }
        if(s.size()==2) return (s[0]==s[1])?true:false;
        if(s[i]!=s[j] && (i!=j || i-j > 2 || j-i > 2)) return false;
        return true;
    }
};