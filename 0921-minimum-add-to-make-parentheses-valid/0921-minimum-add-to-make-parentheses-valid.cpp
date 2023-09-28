class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                if(s[i] == ')'){
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        st.push(')');
                    }
                }
                else{
                    st.push('(');
                }
            }
            else{
                st.push(s[i]);
            }
        }
        int count = 0;
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};