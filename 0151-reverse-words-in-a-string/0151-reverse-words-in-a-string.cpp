class Solution {
public:
    string reverseWords(string s) {
        string ans; bool dy = false;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        while(i<s.size()){
            stack<char> st;
            while(i<s.size() && s[i]!=' '){
                st.push(s[i]); i++;
            }
            if(dy){
                ans.push_back(' ');
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            dy = true;
            while(i<s.size() && s[i]==' '){
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};