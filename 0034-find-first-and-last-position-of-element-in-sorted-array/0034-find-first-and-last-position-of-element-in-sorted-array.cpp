class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> ans; int t1=-1,t2=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                int x=mid,y=mid;
                while(x>=0 && nums[x]==target){
                    x--;
                }
                while(y<nums.size() && nums[y]==target){
                    y++;
                }
                t1=x+1,t2=y-1; break; 
            }
            if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};