class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int start=0, minStart, maxStart;
        bool minf=false, maxf=false;

        for(int i=0; i<nums.size(); i++){
            int num= nums[i];
            if(num<minK || num>maxK){
                minf=false;
                maxf=false;
                start= i+1;
            }
            if(num==minK){
                minf=true;
                minStart=i;
            }
            if(num==maxK){
                maxf=true;
                maxStart= i;
            }

            if(maxf && minf){
                ans += (min(minStart,maxStart)-start+1); 
            }
        }
        return ans;
    }
};
