class Solution {
public:
    string reverseWords(string s) {
        string ans; bool dy = false;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        stack<string> st;
        while(i<s.size()){
            string temp;
            while(i<s.size() && s[i]!=' '){
                temp.push_back(s[i]); i++;
            }
            if(dy && i!=s.size()-1){
                temp.push_back(' ');
            }
            st.push(temp);
            dy = true;
            while(i<s.size() && s[i]==' '){
                i++;
            }
        }
        while(!st.empty()){
            ans = ans + st.top(); st.pop();
        }
        return ans;
    }
};