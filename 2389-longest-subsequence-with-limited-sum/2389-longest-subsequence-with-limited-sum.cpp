class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0) nums[i]+=nums[i-1];
        }
        vector<int> ans; 
        vector<int>::iterator lower, upper;
        for(int i=0; i<q.size(); i++){
            int x = upper_bound(nums.begin(), nums.end(), q[i]) - nums.begin();
            ans.push_back(x);
        }
        return ans;
        // lower_bound(nums.begin(),nums.end(),q[i]);
    }
};