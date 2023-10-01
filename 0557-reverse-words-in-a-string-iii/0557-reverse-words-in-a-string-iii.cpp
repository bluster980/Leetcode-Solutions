class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' '); int i=0;
        int l,r; string ans;
        while(i<s.size()){
            l=i;
            while(s[i]!=' '){
                i++;
            }
            r=i;
            for(int j=r; j>=l; j--){
                ans.push_back(s[j]);
            }
            // ans.push_back(' ');
            i++;
        }
        ans.erase(ans.begin());
        return ans;
    }
};