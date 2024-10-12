class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq; 

        for(vector<int> it: intervals){
            int startPoint = it[0];
            int endPoint   = it[1];

            if(!pq.empty() && startPoint > pq.top()){
                pq.pop();
            }

            pq.push(endPoint);
        }

        return pq.size();
    }
};