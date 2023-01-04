class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> mp; set<char> st,st2;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                mp[s[i]] = t[i];
                st2.insert(s[i]);
                st.insert(t[i]);
            }
        }
        return (true && st.size()==st2.size());
    }
};