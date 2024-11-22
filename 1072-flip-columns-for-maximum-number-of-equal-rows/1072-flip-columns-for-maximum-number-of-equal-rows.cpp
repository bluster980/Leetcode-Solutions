class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        int ans=1;
        for(auto x:matrix){
            string key="";
            string rey=""; 
            for(auto m:x){
                key+=to_string(m);
                rey+=to_string(1-m);
            }
            if(mp.find(key)!=mp.end()){
                mp[key]++;
                ans=max(ans,mp[key]);
            }
            else if(mp.find(rey)!=mp.end()){
                mp[rey]++;
                ans=max(ans,mp[rey]);
            }
            else{
                mp[key]++;
            }
            
        }
        return ans;
    }
};