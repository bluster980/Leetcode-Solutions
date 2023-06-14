class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v(t.size(),0); stack<int> st; st.push(0);
        for(int i=1; i<t.size(); i++){
            while(!st.empty() && t[st.top()] < t[i]){
                int temp = st.top();
                if(t[temp] < t[i]){
                    v[temp] = i-temp;
                }
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};