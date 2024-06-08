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
                int j = 0;
                while(j < temp.size()){
                    if(mp.count(temp.substr(0,j))){
                        ans += temp.substr(0,j); break;
                    }
                    j++;
                }
                if(j == temp.size()){
                    ans += temp;
                }
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
            
        }
        return ans;
    }
};