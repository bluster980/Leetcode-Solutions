class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        char chr; int maxx=INT_MIN;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            if(mp[s[i]] > maxx){
                chr = s[i];
                maxx = mp[s[i]];
            }
        }
        
        if(maxx > ceil(s.size()/2.0)){
            return "";
        }
        int i=0;
        while(mp[chr]){
            s[i] = chr;
            i+=2;
            mp[chr]--;
        }
        for(auto xx:mp){
            char chr = xx.first;
            while(mp[chr]){
                if(i>=s.size()) i=1;
                s[i] = chr;
                i+=2;
                mp[chr]--;
            }
        }
        return s;
    }
};