class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x = __gcd(str1.size(),str2.size());
        string temp = str2;
        str2+=str1; str1+=temp;
        string ans;
        for(int i=0; i<x; i++){
            ans.push_back(str1[i]);
        }
        if(str1==str2) return ans;
        return "";
    }
};