class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end());
        long long x = 0, ans = 0, i=h.size()-1;
        while(i>=0 && k--){
            ans += max(0*1ll,(h[i]-x)); x++;
            i--;
        }
        return ans;
    }
};