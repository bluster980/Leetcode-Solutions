class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int in = 0; string ans = "";
        while(in < strs[0].size()){
            for(int i=1; i<strs.size(); i++){
                if(strs[i][in] != strs[i-1][in]){
                    return ans;
                }
            }
            ans.push_back(strs[0][in]);
            in++;
        }
        return ans;
    }
};