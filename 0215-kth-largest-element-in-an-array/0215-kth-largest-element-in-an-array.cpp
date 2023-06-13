class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int,greater<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto xx:mp){
            while(xx.second && k--){
                xx.second--;
                if(k==0) return xx.first;
            } 
        }
        return 0;
        
    }
};