class Solution {
public:
    void revers(vector<int> &nums, int i, int j){
        if(i>j) return;
        swap(nums[i],nums[j]);
        revers(nums,i+1,j-1);
    }
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()) k%=nums.size();
        revers(nums,0,nums.size()-k-1);
        revers(nums,nums.size()-k,nums.size()-1);
        revers(nums,0,nums.size()-1);
        // reverse(nums.begin(),nums.end()-k);
        // reverse(nums.end()-k,nums.end());
        // reverse(nums.begin(),nums.end());
    }
};