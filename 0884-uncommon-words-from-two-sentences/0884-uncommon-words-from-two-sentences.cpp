class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans; s1.push_back(' '); s2.push_back(' ');
        map<string, int> mp;
        for(int i=0; i<s1.size(); i++){
            string temp;
            while(s1[i]!=' '){
                temp.push_back(s1[i]); i++;
            }
            mp[temp]++;
        }
        for(int i=0; i<s2.size(); i++){
            string temp;
            while(s2[i] != ' '){
                temp.push_back(s2[i]); i++;
            }
            mp[temp]++;
        }
        for(auto xx:mp){
            if(xx.second == 1){
                ans.push_back(xx.first);
            }
        }
        return ans;
    }
};