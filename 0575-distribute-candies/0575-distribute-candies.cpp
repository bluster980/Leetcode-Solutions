class Solution {
public:
    int distributeCandies(vector<int>& cT) {
        unordered_map<int,int> mp;
        for(int i=0; i<cT.size(); i++){
            mp[cT[i]]++;
        }
        return min(mp.size(),cT.size()/2);
    }
};