class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        priority_queue <int> pq;
        vector <pair <int,int>> vec;

        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        
        int i=0;
        while(k>0){
            while(i<n && vec[i].first<=w){
            
                pq.push(vec[i].second);
                i++;
            }
            if(!pq.empty()){
                
                w+=pq.top();
                pq.pop();
                k--;
            }
            else{
                break;
            }


        }
        return w;

        
    }
};