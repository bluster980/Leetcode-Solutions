class Solution {
public:
    void all_subsets(vector<int>& nums,int idx,vector<vector<int>>& subsets,vector<int>& result){
        subsets.push_back(result);
        for(int i=idx;i<nums.size();i++){
            result.push_back(nums[i]);
            all_subsets(nums,i+1,subsets,result);
            result.pop_back();
        }
    }
    int max_or(vector<int>& nums){
        if(nums.size()<1)return 0;
        if(nums.size()==1)return nums[0];
        int max_or=nums[0];
        for(int i=1;i<nums.size();i++){
            max_or=(max_or | nums[i]);
        }
        return max_or;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int req_or=max_or(nums);
        int count=0;
        vector<vector<int>>subsets;
        vector<int>result;
        all_subsets(nums,0,subsets,result);
        for(auto it:subsets){
            int opr=max_or(it);
            if(opr==req_or)count++;
        }
        return count;
    }
};