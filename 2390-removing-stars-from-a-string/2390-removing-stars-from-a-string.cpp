class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};