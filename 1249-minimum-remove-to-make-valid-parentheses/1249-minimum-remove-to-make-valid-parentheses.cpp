class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')' || s[i]=='('){
                if(s[i]==')'){
                    if(!st.empty() && s[st.top()]=='('){
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            s.erase(s.begin() + st.top());
            // cout<<st.top()<<" ";
            st.pop();
        }
        return s;
    }
};