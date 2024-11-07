class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;

        for(int i = 0; i < 24; i++){
            int count = 0;
            for(int& it : candidates){
                if((it & (1 << i)) != 0){
                    count++;
                }
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};