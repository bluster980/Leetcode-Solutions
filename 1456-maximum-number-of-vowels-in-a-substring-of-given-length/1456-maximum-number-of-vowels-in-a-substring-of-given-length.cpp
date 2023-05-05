class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i=0; i<k; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            } 
        }
        int maxx = count; int x = 0;
        for(int i=k; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            }
            if(s[x]=='a' || s[x]=='e' || s[x]=='i' || s[x]=='o' || s[x]=='u'){
                count--;
            }
            x++;
            maxx = max(maxx,count);
        }
        return maxx;
    }
};