class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' '); int i=0;
        int l; string ans;
        while(i<s.size()){
            l=i;
            while(s[i]!=' '){
                i++;
            }
            for(int j=i; j>=l; j--){
                ans.push_back(s[j]);
            } i++;
        }
        ans.erase(ans.begin());
        return ans;
    }
};