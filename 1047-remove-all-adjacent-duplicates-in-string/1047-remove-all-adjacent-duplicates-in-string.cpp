class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st; string ans;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                if(st.top()!=s[i]){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};