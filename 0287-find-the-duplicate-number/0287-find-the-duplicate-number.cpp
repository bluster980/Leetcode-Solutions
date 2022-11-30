class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int i = 0;
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
            // cout<<v[i]<<" ";
            if(v[i]!=i+1){
                // cout<<v[i]<<endl;
                return v[i];
            }
        }
        return v.size()-1;
    }
};