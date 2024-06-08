class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,int> mp; s.push_back(' ');
        for(int i=0; i<d.size(); i++){
            mp[d[i]]++;
        }
        int j=0; string ans; 
        for(int i=0; i<s.size(); i++){
            string temp; bool flag = false;
            while(s[i] != ' '){
                temp = string(s.begin()+j , s.begin()+i);
                if(mp.find(temp) != mp.end()){
                    ans += temp; flag = true;
                    ans.push_back(' ');
                    while(s[i] != ' ') i++;
                    continue;
                }
                i++;
                
            }
            if(!flag){
                temp.push_back(s[i-1]); 
                ans += temp; 
                ans.push_back(' ');
            }
            j = i+1;
        }
        ans.pop_back();
        return ans;
    }
};