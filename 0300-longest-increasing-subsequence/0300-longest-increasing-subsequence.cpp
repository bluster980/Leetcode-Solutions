class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int v[nums.size()];
        for(int i=0; i<nums.size(); i++) v[i]=1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    v[i] = max(v[j]+1,v[i]);
                }
            }
        }
        return *max_element(v,v+nums.size());
    }
};