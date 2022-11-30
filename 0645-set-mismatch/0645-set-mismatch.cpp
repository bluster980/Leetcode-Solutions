class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int i = 0; vector<int> ans;
        while(i<v.size()){
            if(v[i]-1==i || v[i]==v[v[i]-1]){
                i++;
            }
            else{
                swap(v[v[i]-1],v[i]);
            }
        }
        // cout<<v.size();
        for (int i = 0; i < v.size(); ++i)
        {
            // cout<<v[i]<<" ";
            if(v[i]!=i+1){
                // cout<<i+1<<" "<<v[i]<<endl;
                // return v[i];
                ans.push_back(v[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};