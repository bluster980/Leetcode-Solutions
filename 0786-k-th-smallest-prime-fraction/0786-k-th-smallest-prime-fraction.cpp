class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double, vector<double>, greater<double>> pq;
        map<double, pair<int,int>> mp;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                double temp = (arr[i]*1.0/arr[j]);
                // cout<<temp<<endl;
                pq.push(temp); mp[temp] = {arr[i],arr[j]};
            }
        }
        k--;
        while(k--){
            pq.pop();
        }
        // for(auto xx:mp){
        //     cout<<xx.first<<" "<<xx.second.first<<" "<<xx.second.second<<endl;
        // }
        return {mp[pq.top()].first, mp[pq.top()].second};
    }
};