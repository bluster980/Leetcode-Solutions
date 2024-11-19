vector<int> count_num(100002,0);

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long i=0, j=0, sum=0, max_sum=0;
        while(j<nums.size())
        {
            count_num[nums[j]]++;
            sum+=nums[j];
            while(count_num[nums[j]]>1)
            {
                count_num[nums[i]]--;
                sum-=nums[i];
                i++;
            }

            if(j-i+1==k)
            {
                max_sum=max(sum, max_sum);
                count_num[nums[i]]--;
                sum-=nums[i];
                i++;
            }
          
            j++;
        }

        for(int num: nums)
            count_num[num]=0;
        
        return max_sum;
    }
};