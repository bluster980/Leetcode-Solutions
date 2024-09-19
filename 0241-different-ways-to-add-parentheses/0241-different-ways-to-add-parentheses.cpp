class Solution {
public:
vector<int>solve(string s){
    vector<int>ans;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
            vector<int>left_result=solve(s.substr(0,i));
             vector<int>right_result=solve(s.substr(i+1));

             for( int x: left_result){
                for(int y:right_result){
                    if(s[i]=='+'){
                        ans.push_back(x+y);
                    }
                    else if( s[i]=='-'){
                        ans.push_back(x-y);
                    }
                    else {
                        ans.push_back(x*y);
                    }
                }
             }

        }
        
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        
    }
    return ans;
}
    vector<int> diffWaysToCompute(string s) {
       return  solve(s);
    }
};