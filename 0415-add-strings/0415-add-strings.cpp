class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans;
        int temp = 0; int range = max(num1.size(),num2.size());
        for(int i=0; i<range; i++){
            if(i<num1.size()){
                temp += (num1[i]-'0');
            }
            if(i<num2.size()){
                temp += (num2[i]-'0');
            }
            // cout<<temp<<" ";
            // if(temp > 9){
                // cout<<(temp%9 + '0')<<endl;
                ans.push_back(temp%10 + '0');
                temp/=10;
            // }
            // else{
                // ans.push_back(temp + '0');
            // }
        }
        if(temp > 0) 
            ans.push_back(temp+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};