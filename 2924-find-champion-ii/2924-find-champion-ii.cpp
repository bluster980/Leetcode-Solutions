class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto it : edges){
            indegree[it[1]]++;
        }
        set<int> st;
        for(int i = 0; i < n ; i++){
            if(indegree[i] == 0){
                st.insert(i);
            }
        }
        if(st.size() > 1) return -1;
        else return *st.begin();

    }
};