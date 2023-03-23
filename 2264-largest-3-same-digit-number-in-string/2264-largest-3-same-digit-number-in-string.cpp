class Solution {
public:
    string largestGoodInteger(string num) {
        int maxx = INT_MIN; int in = 0;
        for(int i=0; i<num.size(); i++){
            if(i>1 && (num[i]==num[i-1] && num[i]==num[i-2])){
                if(num[i]-'0' > maxx){
                    maxx = max(maxx,num[i]-'0');
                    in = i;
                }
            }
        }
        if(maxx == INT_MIN) return "";
        return string(3,num[in]);
    }
};