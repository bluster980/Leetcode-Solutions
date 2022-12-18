class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> st; unordered_map<int,int> mp;
        for(int i=0; i<n2.size(); i++){
            while(!st.empty() && n2[i]>st.top()){
                mp[st.top()] = n2[i];
                st.pop();
            }
            // else{
            st.push(n2[i]);
            // }
        }
        vector<int> ans;
        for(int i=0; i<n1.size(); i++){
            if(mp[n1[i]]==0) ans.push_back(-1);
            else ans.push_back(mp[n1[i]]);
        }
        return ans;
    }
};