class Solution {
public:
    string reverseWords(string s) {
        int i=0; string ans; s.push_back(' ');
        while(i<s.size()){
            string temp;
            while(s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            reverse(temp.begin(),temp.end());
            temp.push_back(' ');
            ans = ans + temp;
            // ans = ans + 
            i++;
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};