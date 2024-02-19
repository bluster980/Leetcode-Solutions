class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majcnt = 0, can = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == can){
                majcnt++;
            }
            else if(!majcnt){
                can = nums[i];
                majcnt++;
            }
            else{
                majcnt--;
            }
        }
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == can) cnt++;
        }
        if(cnt > nums.size()/2)
            return can;
        return -1;
    }
};