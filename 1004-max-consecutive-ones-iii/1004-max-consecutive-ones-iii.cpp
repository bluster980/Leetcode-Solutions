class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int zero = 0, maxx = 0;
        int i=0,j=0, n = nums.size();
        while(i<n){
            if(nums[i] == 0){
                zero++;
                if(zero > k){
                    while(nums[j] != 0){
                        j++;
                    }
                    j++; zero--;
                }
            }
            maxx = max(maxx, i-j+1);
            i++;
        }
        return maxx;
    }
};