class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,int> mp; s.push_back(' ');
        for(int i=0; i<d.size(); i++){
            mp[d[i]]++;
        }
        vector<string> temp;
        int i=0, j = 0;
        while(i < s.size()){
            while(s[i] != ' '){
                i++;
            }
            string dumy = string(s.begin()+j, s.begin()+i);
            // cout<<dumy<<endl;
            temp.push_back(dumy);
            i++; j = i;
        }
        string ans;
        for(int i=0; i<temp.size(); i++){
            int k = 0;
            while(k <= temp[i].size()){
                if(mp.find(temp[i].substr(0, k)) != mp.end()){
                    ans += temp[i].substr(0, k);
                    ans.push_back(' ');
                    break;
                }
                k++;
            }
            if(k > temp[i].size()){
                ans += temp[i];
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;
    }
};