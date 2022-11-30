class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int i = 0;
        while(i<v.size()){
            if(v[i]>=v.size() || v[i]<=0 || v[i]-1==i){
                i++;
            }
            else if(v[i]!=v[v[i]-1]){
                swap(v[v[i]-1],v[i]);
            }
            else{
                i++;
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i]!=i+1){
                return (int)i+1;
            }
        }
        return (int)i+1;
    }
};