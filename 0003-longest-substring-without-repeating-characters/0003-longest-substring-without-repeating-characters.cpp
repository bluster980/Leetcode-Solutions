class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        unordered_map<char,int> mp;
        int maxx = 0;
        while(r < s.size()){
            if(mp.find(s[r]) != mp.end() && (mp[s[r]] >= l)){
                l = max(l,(mp[s[r]]+1));
            }
            mp[s[r]] = r;
            maxx = max(maxx,r-l+1);
            r++;
        }
        return maxx;
    }
};