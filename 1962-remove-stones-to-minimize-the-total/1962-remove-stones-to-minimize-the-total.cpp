class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq,rq;
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);            
        }
        int ans = 0;
        while(k--){
            pq.push(ceil(pq.top()/2.0)); 
            pq.pop();
        }
        while(!pq.empty()){
            ans+=pq.top(); pq.pop();
        }
        return ans;
        // return 0;
    }
};