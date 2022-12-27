class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> ans;
        for(int i=0; i<rocks.size(); i++){
            ans.push_back(capacity[i]-rocks[i]);
        }
        sort(ans.begin(),ans.end());
        int count = 0;
        for(int i=0; i<ans.size(); i++){
            // cout<<ans[i]<<" ";
            if((additionalRocks > 0 && additionalRocks >= ans[i]) || ans[i]==0){
                additionalRocks-=ans[i];
                count++;
            }
        }
        // cout<<endl;
        return count;
    }
};