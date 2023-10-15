class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end()); int cnt=0;
        for(int k=2; k<nums.size(); k++){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j] > nums[k]){
                    cnt += (j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return cnt;
    }
};