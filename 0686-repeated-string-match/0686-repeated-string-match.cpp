class Solution {
public:
    bool isSubString(string x, string y){
        if(x.find(y) != string::npos){
            return 1;
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        string temp = a; int cnt = 1;
        while(temp.size() < b.size()){
            temp = temp + a; cnt++;
            if(isSubString(temp,b)) return cnt;
        }
        if(isSubString(temp,b)) return cnt;
        temp = temp+a;
        if(isSubString(temp,b)) return cnt+1;
        return -1;
    }
};