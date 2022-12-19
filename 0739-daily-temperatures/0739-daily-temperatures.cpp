class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st; unordered_map<int,int> mp;
        for(int i=0; i<t.size(); i++){
            while(!st.empty() && (t[i] > t[st.top()])){
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int i=0; i<t.size(); i++){
            ans.push_back((mp.find(i)==mp.end()?0:(mp[i]-i)));
        }
        return ans;
    }
};