class Solution {
public:

    int findInd(vector<vector<int>>& items,int x){

        int low=0;
        int high=items.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(items[mid][0]<=x){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return low-1;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }

        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ind=findInd(items,queries[i]);
            if(ind==-1){
                ans.push_back(0);
                continue;
            }
            ans.push_back(items[ind][1]);
        }
        return ans;
    }
};