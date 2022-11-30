class Solution {
public:
    int missingNumber(vector<int>& v) {
        int i = 0;
        while(i<v.size()){
            if(v[i]==i || v[i]>=v.size()){
                i++;
            }
            else{
                swap(v[v[i]],v[i]);
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i]!=i){
                return i;
            }
        }
        return i;
    }
};