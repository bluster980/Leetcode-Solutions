class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        stack<pair<int,int>> st;
        for(int i=0; i<in.size(); i++){
            if(!st.empty()){
                pair<int,int> temp = st.top();
                if(in[i][0] >= temp.first && in[i][1] <= temp.second){
                    continue;
                }
                else if(in[i][0] == temp.first && in[i][1] >= temp.second){
                    st.pop();
                }
            }
            st.push({in[i][0], in[i][1]});
        }
        int cnt = 0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};