class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0,cptl = 0;
        for(int i=0; i<word.size(); i++){
            (word[i]-'0' >= 17 && word[i]-'0'<=42)?cptl++:small++;
        }
        if(small==word.size() || (small==word.size()-1 && (word[0]-'0' >= 17 && word[0]-'0'<=42)) || cptl==word.size()){
            return true;
        }
        return false;
    }
};