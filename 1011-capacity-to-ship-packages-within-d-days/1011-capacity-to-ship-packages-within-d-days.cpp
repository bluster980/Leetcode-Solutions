class Solution {
    int binarySearch(vector<int>& weights, int days, int l, int r){
        if(r<l) return l;
        int capacity = (l+r)/2, d=0, sum=0;
        for(auto i:weights){
            sum+=i;
            if(sum==capacity){
                d++;
                sum=0;
            }
            else if(sum>capacity){
                d++;
                sum=i;
            }
        }
        if(sum>0) d++;
        if(d>days) return binarySearch(weights, days, capacity+1,r);
        return binarySearch(weights,days, l, capacity-1);
    }
    public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, r=0;
        for(auto i:weights){
            if(i>l) l=i;
            r+=i;
        }
        return binarySearch(weights, days, l,r);
    }
};