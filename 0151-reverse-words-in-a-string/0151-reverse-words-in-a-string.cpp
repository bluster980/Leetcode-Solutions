class Solution {
public:
    string reverseWords(string s) {
        stack<string> st; s.push_back(' ');
        for(int i=0; i<s.size(); i++){
            string temp = "";
            while(s[i]!=' '){
                temp.push_back(s[i]); i++;
            }
            // cout<<temp<<endl;
            if(temp.size() > 0)
                st.push(temp);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            ans += ' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};