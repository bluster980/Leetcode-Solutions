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
                int j = 0;
                while(j < temp.size()){
                    if(mp.count(temp.substr(0,j))){
                        ans += temp.substr(0,j);
                        ans += " "; break;
                    }
                    j++;
                }
                if(j == temp.size()){
                    ans += temp;
                    ans += " ";
                }
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
            
        }
        ans.pop_back();
        return ans;
    }
};