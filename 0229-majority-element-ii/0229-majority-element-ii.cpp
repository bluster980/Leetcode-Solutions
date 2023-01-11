class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first=-1,second=-1,fc=0,sc=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==first){
                fc++;
            }
            else if(nums[i]==second){
                sc++;
            }
            else if(!fc) {first = nums[i]; fc = 1;}
            else if(!sc) {second = nums[i]; sc = 1;}
            else{fc--; sc--;}
            
        }
        vector<int> ans;
        int count1=0,count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == first) count1++;
            else if(nums[i] == second) count2++;
        }
        if(count1 > floor(nums.size()/3.0)) {ans.push_back(first);}
        if(count2 > floor(nums.size()/3.0)) {ans.push_back(second);}
        return ans;
    }
};