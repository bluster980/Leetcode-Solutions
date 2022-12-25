class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end()); vector<int> ans; 
        for(int i=0; i<nums.size(); i++){
            if(i>0) nums[i]+=nums[i-1];
        }
        for(int i=0; i<q.size(); i++){
            ans.push_back(upper_bound(nums.begin(), nums.end(), q[i]) - nums.begin());
        }
        return ans;
    }
};