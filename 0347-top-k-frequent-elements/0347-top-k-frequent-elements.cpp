class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(!pq.empty() && k>0){
            cout<<pq.top().second<<" ";
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        
        // multimap<int,int,greater<int>> mp2;
        // for(auto x:mp){
        //     // cout<<x.first<<" "<<x.second<<endl;
        //     mp2.insert({x.second,x.first});
        // }
        
        // for(auto y:mp2){
        //     ans.push_back(y.second);
        //     // cout<<y.first<<" "<<y.second<<endl;
        //     k--;
        //     if(k==0) break;
        // }
        return ans;
    }
};