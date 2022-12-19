class Solution {
#include <bits/stdc++.h>
public:
    int nextGreaterElement(int n) {
        string x = to_string(n);
        next_permutation(x.begin(),x.end());
        int ans = stoll(x);
        if(ans <= n) return -1;
        return ans;
    }
};