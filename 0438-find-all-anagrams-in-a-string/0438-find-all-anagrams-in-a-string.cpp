class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp,pp;
        for(int i=0; i<p.size(); i++){
            pp[p[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<p.size(); i++){
            mp[s[i]]++;
        }
        if(mp == pp) ans.push_back(0); 
        int k=0;
        for(int i=p.size(); i<s.size(); i++){
            if(mp[s[k]] == 1) 
                mp.erase(s[k]);
            else 
                mp[s[k]]--;
            mp[s[i]]++; k++;
            if(mp == pp) ans.push_back(k);
            // for(auto xx:mp){
            //     cout<<xx.first<<" "<<xx.second<<endl;
            // }
            // cout<<endl;
        }
        return ans;
    }
};