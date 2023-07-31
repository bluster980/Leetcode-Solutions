class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0); int maxx = 0; int i=0;
        while(i<nums.size()){
            int count = 0;
            while(nums[i]!=0){
                i++; count++;
            }
            maxx = max(maxx,count);
            i++;
        }
        return maxx;
    }
};