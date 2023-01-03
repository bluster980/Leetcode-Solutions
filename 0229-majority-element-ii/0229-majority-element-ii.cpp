class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int curr1=INT_MIN,curr2=INT_MIN,cnt1=0,cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==curr1) cnt1++;
            else if(nums[i]==curr2) cnt2++;
            else if(cnt1 == 0) curr1=nums[i],cnt1++;
            else if(cnt2 == 0) curr2=nums[i],cnt2++;
            else {cnt1--; cnt2--;}
        }
        int count1=0,count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==curr1) count1++;
            else if(nums[i]==curr2) count2++;
        }
        if(count1 > nums.size()/3) ans.push_back(curr1);
        if(count2 > nums.size()/3) ans.push_back(curr2);
        
        return ans;
    }
};