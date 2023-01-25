class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        int ans = 0; int maxx = 0; int odd = 0;
        for(auto xx:mp){
            // cout<<xx.first<<" "<<xx.second<<endl;
            if(xx.second%2){
                odd++;
                ans+=(xx.second-1);
            }
            else
                ans+=xx.second;
        }
        if(odd) ans++;
        return ans;
    }
};