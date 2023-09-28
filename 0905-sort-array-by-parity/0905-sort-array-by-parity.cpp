class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            if(i<j && nums[i]%2!=0){
                while(i<j && nums[j]%2!=0){
                    j--;
                    cout<<j<<endl;
                }
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};