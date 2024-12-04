class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int count = 0, k = 0;
        for(int i=0; i<str1.size(); i++){
            if(k<str2.size() && (str1[i] == str2[k] || str1[i]+1 == str2[k] || str1[i]-25 == str2[k])){
                count++; k++;
            }
        }
        return count == str2.size();
    }
};