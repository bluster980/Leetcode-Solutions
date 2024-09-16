class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v ;
        int n = timePoints.size();
        int ans = INT_MAX ;

        for(auto time : timePoints){
            int t = stoi(time.substr(0,2))*60 ;
            t += stoi(time.substr(3));
            v.push_back(t);
        }

        sort(v.begin() , v.end());

        for(int i=1 ; i<n ; i++){
            ans = min(ans , v[i] - v[i-1]);
        }

        ans = min(ans , (24*60 + v[0]) - v[n-1]);

        return ans ;
    }
};