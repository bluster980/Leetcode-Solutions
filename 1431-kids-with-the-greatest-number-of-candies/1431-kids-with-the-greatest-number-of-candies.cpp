class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        int maxx = *max_element(c.begin(),c.end());
        vector<bool> v;
        for(int i=0; i<c.size(); i++){
            if(c[i]+ec >= maxx){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        return v;
    }
};