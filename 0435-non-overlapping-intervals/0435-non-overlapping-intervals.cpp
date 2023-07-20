class Solution {
public:
    static bool comparator(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        // for(int i=0; i<intervals.size(); i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        int count = 0; int endTime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= endTime){
                endTime = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count-1;
    }
};