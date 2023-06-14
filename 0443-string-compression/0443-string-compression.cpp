class Solution {
public:
    int compress(vector<char>& c) {
        vector<char> ans; if(c.size()==1) return 1; c.push_back('999999');
        for(int i=1; i<c.size(); i++){
            int temp = 1;
            while(i<c.size() && c[i]==c[i-1]){
                temp++; i++;
            }
            ans.push_back(c[i-1]);
            if(temp > 1){
                string xx = to_string(temp);
                for(int j=0; j<xx.size(); j++){
                    ans.push_back(xx[j]);
                }
            }
        }
        c = ans;
        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        return ans.size();
    }
};