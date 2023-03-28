class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string x,y;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='-') {
                if(s[i]>='a' && s[i]<='z'){
                    // char temp = s[i]-32;
                    // cout<<temp<<" ";
                    x.push_back(char(s[i]-32));
                }
                else{
                    x.push_back(s[i]);
                }
            }
        }
        if(x.size() == 0) return "";
        reverse(x.begin(),x.end());
        int i=0;
        while(i<x.size()){
            int temp = k;
            while(temp--){
                if(i<x.size())
                    y.push_back(x[i]);
                i++;
            }
            y.push_back('-');
        }
        y.pop_back();
        reverse(y.begin(),y.end());
        return y;
    }
};