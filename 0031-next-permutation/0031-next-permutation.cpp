class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = INT_MIN;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                temp = i-1; break;
            }
        }
        // cout<<temp<<endl;
        if(temp!=INT_MIN){
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > nums[temp]){
                swap(nums[i],nums[temp]); break;
            }
        }
        reverse(nums.begin()+temp+1,nums.end());}
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};