class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        for(int i = e.size()-k-1; i>=0; i--){
            e[i] += e[i+k];
        }
        return *max_element(e.begin(), e.end());
    }
};