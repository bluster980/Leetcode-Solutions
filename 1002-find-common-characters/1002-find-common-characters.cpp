class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
        unordered_map<char,int> mp;
        for(int j=0; j<w[0].size(); j++){
            mp[w[0][j]]++;
        }
        for(int i=1; i<w.size(); i++){
            unordered_map<char,int> mp1;
            for(int j=0; j<w[i].size(); j++){
                if(mp.find(w[i][j]) != mp.end()){
                    if(mp[w[i][j]] == 1) mp.erase(w[i][j]);
                    else mp[w[i][j]]--;
                    mp1[w[i][j]]++;
                }
            }
            mp = mp1;
        }
        vector<string> ans;
        for(auto xx:mp){
            for(int i=0; i<xx.second; i++){
                string temp;
                temp.push_back(xx.first);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};