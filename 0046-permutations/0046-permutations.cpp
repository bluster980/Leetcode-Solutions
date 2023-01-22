class Solution {
public:
    unsigned int factorial(unsigned int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return n * factorial(n - 1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(nums);
        int temp = factorial(nums.size()) - 1;
        while(temp--){
            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};