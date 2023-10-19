class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st; int i=0;
        string sn,tn;
        while(i<s.size()){
            if(!st.empty() && s[i] == '#'){
                st.pop();
            }
            else if(s[i] != '#'){
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            sn.push_back(st.top());
            st.pop();
        }
        i = 0;
        while(i<t.size()){
            if(!st.empty() && t[i] == '#'){
                st.pop();
            }
            else if(t[i] != '#'){
                st.push(t[i]);
            }
            i++;
        }
        while(!st.empty()){
            tn.push_back(st.top());
            st.pop();
        }
        // cout<<sn<<" "<<tn<<endl;
        return sn==tn;
    }
};