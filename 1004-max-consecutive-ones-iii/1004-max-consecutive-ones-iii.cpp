class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        queue<int> q; int zero = 0, maxx = 0;
        int i=0, n = nums.size();
        while(i<n){
            if(nums[i] == 0){
                zero++;
                if(zero > k){
                    while(!q.empty() && q.front()!=0){
                        q.pop();
                    }
                    q.pop(); zero--;
                }
            }
            q.push(nums[i]);
            maxx = max(maxx, (int)q.size());
            i++;
        }
        return maxx;
    }
};