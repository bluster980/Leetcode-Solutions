class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        vector<int> ans; int index = n;
        for(int i=0; i<spells.size(); i++){
            if((long long)spells[i]*(long long)potions[potions.size()-1] < success) ans.push_back(0);
            else{
                int l = 0, r = potions.size()-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    long long product = (long long)spells[i] * potions[mid];
                    if(product >= success){
                        index = mid;
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }
                ans.push_back(n-index);
            }
        }
        return ans;
    }
};