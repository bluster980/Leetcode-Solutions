class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,int> mp; s.push_back(' ');
        for(int i=0; i<d.size(); i++){
            mp[d[i]]++;
        }
        string temp; string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(ans.size()>0) ans += ' ';
                int j = 0; string dumy;
                while(j < temp.size()){
                    dumy.push_back(temp[j]);
                    if(mp.count(dumy)){
                        break;
                    }
                    j++;
                }
                ans += dumy;
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
            
        }
        return ans;
    }
};