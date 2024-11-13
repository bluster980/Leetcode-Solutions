class Solution {
public:
    long long countFairPairs(vector<int>& v, int L, int right) {
        sort(v.begin(),v.end());
        int R = v.size() - 1; long long count = 0;
        while (R > 0) {
            vector<int>::iterator it1,it2;
            it1 = lower_bound(v.begin(), v.end(),L-v[R]);
            int st = it1 - v.begin();
            it2 = upper_bound(v.begin(), v.end(),right-v[R]);
            --it2;
            int le = it2 - v.begin();
            le = min(le, R - 1);
            if (le - st >= 0) {
                count += (le - st + 1);
            }
            R--;
        }
        return count;
    }
};