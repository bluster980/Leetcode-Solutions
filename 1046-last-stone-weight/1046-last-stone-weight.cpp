class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq;
        for(int i=0; i<s.size(); i++){
            pq.push(s[i]);
        }
        while(pq.size()>1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x-y != 0) pq.push(x-y);
        }
        return (pq.size()==0)?0:pq.top();
    }
};