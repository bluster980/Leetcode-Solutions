class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            while(nums[i]>0 && nums[i]<nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            i++;
        }
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        int x = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==x){
                x++;
            }
        }
        return x;
    }
};