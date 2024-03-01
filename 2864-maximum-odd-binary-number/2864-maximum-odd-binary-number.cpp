class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans; int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') cnt++;
        }
        for(int i=0; i<cnt-1; i++) ans.push_back('1');
        for(int i=0; i<s.size()-cnt; i++) ans.push_back('0');
        ans.push_back('1');
        return ans;
    }
};