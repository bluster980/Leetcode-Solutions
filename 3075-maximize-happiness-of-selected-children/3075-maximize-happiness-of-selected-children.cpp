class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        priority_queue<long long> pq;
        for(int i=0; i<h.size(); i++){
            pq.push(h[i]);
        }
        long long x = 0, ans = 0;
        while(!pq.empty() && k--){
            ans += max(0*1ll,(pq.top()-x)); x++;
            pq.pop();
        }
        return ans;
    }
};