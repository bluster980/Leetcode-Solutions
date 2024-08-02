class Solution {
public:
    int minSwaps(vector<int>& nums) {
    int sizee = nums.size();
	for (int i = 0; i < sizee; ++i)
	{
		nums.push_back(nums[i]);
	}
	
	vector<int> vc = nums;
	int count = (nums[0]==1) ? 1:0;
	for (int i = 1; i < nums.size(); ++i)
	{
		count += (nums[i]==1) ? 1:0; 
		nums[i]+=nums[i-1];
	}
    if (count == 0)
	{
		return 0;
	}
	int right = count/2;
	int maxx = INT_MIN;
	int ans;
	for (int i = 0; i < nums.size()/2; i++)
	{
		ans = (vc[i]==0) ? nums[right-1]-nums[i] : nums[right-1]-nums[i]+1; 
		right++;
		maxx = max(maxx,ans);
	}
	return (count/2)-maxx; 
    }
};