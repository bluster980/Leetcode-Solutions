class Solution {
public:
    char findTheDifference(string s, string t) {
    char c,ans;
	for(int i=0;i<s.size();i++){
		c^=s[i]^t[i];
	}
    ans = char(c^t[t.size()-1]);
	// cout<<char(c^t[t.size()-1]);
    return ans;
    } 
};