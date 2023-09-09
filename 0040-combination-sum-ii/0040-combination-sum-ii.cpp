class Solution {
public:
    vector<vector<int>> ans; vector<int> arr;
	void rec(int in, int tar, vector<int> v){
		if(tar == 0){
			ans.push_back(v);
			return;
		}
		// else if(tar < 0 || in>=arr.size()){
		// 	return;
		// }
		int pre = in;
		while(in<arr.size()){
			if(in > pre && arr[in]==arr[in-1]){
				// continue;
			}
			else if(arr[in]>tar)
				break;
			else
			{
				v.push_back(arr[in]);
				rec(in+1,tar-arr[in],v);
				v.pop_back();
			}
			in++;
		}
	}
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        arr = c;
        rec(0,target,{});
        return ans;
    }
};