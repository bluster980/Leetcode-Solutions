#define pr pair<int, pair<int, int>>

class cmp {
    public:
        bool operator () (pr a, pr b) {
            int a_sum = a.first + a.second.second;
            int b_sum = b.first + b.second.second;

            if(a_sum == b_sum) return a.first > b.first;
            return a_sum > b_sum;
        }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k, int isSwap = 0) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return kSmallestPairs(nums2, nums1, k, 1);
        vector<vector<int>> ans;

        priority_queue<pr, vector<pr>, cmp> pq;
        for(int i=0; i<n1; i++) pq.push({nums1[i], {0, nums2[0]}});

        while(k-- && !pq.empty()) {
            pr top = pq.top();
            pq.pop();

            int j = top.second.first;
            ans.push_back({top.first, top.second.second});
            if(j + 1 < n2) pq.push({top.first, {j + 1, nums2[j + 1]}});
        }

        if(isSwap) {
            for(int i=0; i<ans.size(); i++) swap(ans[i][0], ans[i][1]);
        }

        return ans;
    }
};