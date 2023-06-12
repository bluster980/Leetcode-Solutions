class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x = __gcd(str1.size(),str2.size());
        string temp = str2;
        for(int i=0; i<str1.size(); i++){
            str2.push_back(str1[i]);
        }
        for(int i=0; i<temp.size(); i++){
            str1.push_back(temp[i]);
        }
        string ans;
        for(int i=0; i<x; i++){
            ans.push_back(str1[i]);
        }
        if(str1==str2) return ans;
        return "";
    }
};