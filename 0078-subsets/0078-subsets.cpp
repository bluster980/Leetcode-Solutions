class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        string s;
        for(int i=0; i<nums.size(); i++){
            s.push_back(nums[i]);
        }
        int bits = pow(2,s.size());
	    vector<vector<int>> vv;
	    for(int i = 0; i<bits; i++){
		    vector<int> v;
		    for (int j = 0; j < s.size(); ++j)
		    {
			    if(i & (1<<j)){
				v.push_back(s[j]);
			}
		}
		vv.push_back(v);
	    }
        return vv;
    }
};