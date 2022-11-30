class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int i = 0; vector<int> ans;
        while(i<v.size()){
            if(v[i]-1==i || v[i]==v[v[i]-1]){
                i++;
            }
            else{
                swap(v[v[i]-1],v[i]);
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i]!=i+1){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};