class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size() == 1) return false;
        map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        int first = INT_MIN,second = INT_MIN;
        for(int i=0; i<s.size(); i++){
            if(s[i] != g[i]){
                if(first == INT_MIN) {first = i;}
                else {second = i; break;}
            }
        }
        if(first!=INT_MIN && second!=INT_MIN){
            swap(s[first],s[second]);
            return s==g;
        }
        return s==g && (mp.size()<s.size());
    }
};