class Solution {
public:
    int titleToNumber(string ct) {
        int ans = 0;
        for(int i=0; i<ct.size(); i++){
            ans = ans*26 + (ct[i]-'A'+1);
        }
        return ans;
    }
};