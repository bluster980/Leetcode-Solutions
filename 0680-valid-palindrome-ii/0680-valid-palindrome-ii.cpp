class Solution {
public:
    bool isPal(string s, int start, int end){
        while(start<end && s[start] == s[end]){
            start++; end--;
        }
        return s[start]==s[end];
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r && s[l] == s[r]){
            l++; r--;
        }
        if(s[l] != s[r]){
            return isPal(s, l+1, r) | isPal(s, l, r-1);
        }
        else return true;
    }
};