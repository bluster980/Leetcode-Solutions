class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0; 
        while(i<s.size()){
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            reverse(s.begin()+i,s.end()-s.size()+j); 
            j++; i = j;
        }
        i=0;
        while(i<s.size() && s[i]==' '){ s.erase(s.begin()+i); }
        reverse(s.begin(),s.end());
        i = 0;
        while(i<s.size() && s[i]==' '){ s.erase(s.begin()+i); }
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==' ' && s[i+1] == ' '){
                s.erase(s.begin()+i); i--;
            }
        }
        return s;
    }
};