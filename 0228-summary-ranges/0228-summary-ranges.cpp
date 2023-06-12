class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> ans;
        int i=0;
        while(i<n.size()){
            int x = i;
            int j = i + 1;
            while(i<n.size()-1 && (n[i]+1) == n[j]){
                i++;
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            if(x!=i){
                ans.push_back(to_string(n[x])+"->"+to_string(n[i]));
            }
            else{
                ans.push_back(to_string(n[x]));
            }
            i++;
        }
        return ans;
    }
};