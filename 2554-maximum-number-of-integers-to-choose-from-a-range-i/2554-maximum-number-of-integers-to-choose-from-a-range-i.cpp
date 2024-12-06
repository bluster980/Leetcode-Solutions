class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int maxi = 0;
        int sum = 0;
        
        set<int> st;
        for( auto &it : banned ) st.insert( it );
        
        for( int i=1 ; i<=n ; i++ ){
            if( st.count(i) == 0 && ((sum+i) <= maxSum )) {
                sum += i;
                maxi++;
            }
        }
        return maxi;
    }
};