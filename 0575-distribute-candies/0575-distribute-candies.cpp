class Solution {
public:
    int distributeCandies(vector<int>& cT) {
        return min(unordered_set<int> (begin(cT),end(cT)).size(),cT.size()/2);
        
    }
};