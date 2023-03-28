class Solution {
public:
    int distributeCandies(vector<int>& cT) {
        set<int> mp;
        for(int i=0; i<cT.size(); i++){
            mp.insert(cT[i]);
            // mp[cT[i]]++;
        }
        return min(mp.size(),cT.size()/2);
    }
};