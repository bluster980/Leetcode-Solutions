class Solution {
public:
    int countSegments(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        if(s.size()!=0 && s[s.size()-1]!=' ')
        {
            s.push_back(' ');
        }
        int count = 0;
        while(i<s.size()){
            if(s[i]==' '){
                count++;
            }
            while(i<s.size() && s[i]==' ') i++;
            i++;
        }
        return count;
    }
};