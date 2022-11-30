class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        int i = 0; vector<int> ans; int yy = v.size();
        while(i<yy){
            if(v[i]-1==i || v[i]==v[v[i]-1]){
                i++;
            }
            else{
                swap(v[v[i]-1],v[i]);
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            // cout<<v[i]<<" ";
            if(v[i]!=i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};