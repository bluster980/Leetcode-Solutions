class Solution {
public:
    int hIndex(vector<int>& c) {
        vector<int> v(c.size()+1,0);
        for(int i=0; i<c.size(); i++){
            if(c[i] < c.size()) v[c[i]]++;
            else v[c.size()]++;
        }
        int count = 0;
        for(int i=c.size(); i>=0; i--){
            count += v[i];
            if(count >= i){
                return i;
            }
        }
        return 0;
    }
};