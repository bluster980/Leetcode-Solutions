class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v(t.size(),0); stack<int> st; st.push(0);
        for(int i=1; i<t.size(); i++){
            while(!st.empty() && t[st.top()] < t[i]){
                v[st.top()] = i-st.top(); st.pop();
            }
            st.push(i);
        }
        return v;
    }
};