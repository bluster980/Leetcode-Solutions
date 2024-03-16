class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int length = INT_MIN;
        map<int,int> mp;
        int sum = 0;
        mp.insert({0,-1});
        for(int i=0;i<nums.size(); i++){
            if (nums[i]==1)
            {
            	sum++;
            }
            else{
            	sum--;
            }
            mp.insert({sum,i});
            int idx;
            if (mp.count(sum)!=0)
            {
            	idx = mp.at(sum);
            	// length = i - idx;
            	length = max(length,(i-idx));
            }

        }
        // cout<<length<<endl;
        return length;
    }
};