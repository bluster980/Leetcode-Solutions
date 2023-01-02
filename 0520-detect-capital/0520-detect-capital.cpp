class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0,cptl = 0; int n = word.size();
        for(int i=0; i<n; i++){
            (word[i]-'0' >= 17 && word[i]-'0'<=42)?cptl++:small++;
        }
        return (small==n || (small==n-1 && (word[0]-'0' >= 17 && word[0]-'0'<=42)) || cptl==n)?true:false;
    }
};