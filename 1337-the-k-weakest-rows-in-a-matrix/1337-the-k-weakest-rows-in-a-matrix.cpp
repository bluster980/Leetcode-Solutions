class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<vector<int>,int> mp;
	for (int i = 0; i < mat.size(); ++i)
	{
		vector<int> vv;
		for (int j = 0; j < mat[i].size(); ++j)
		{
			vv.push_back(mat[i][j]);
			// cout<<v[i][j]<<" ";
		}
		// cout<<endl;
		mp.insert({vv,i});
		// mp[vv] = i;
	}
	int count = 0;
	vector<int> v;
	for(auto x:mp){
		count++;
		// for (int i = 0; i < x.first.size(); ++i)
		// {
		// 	cout<<x.first[i]<<" ";
		// }
		v.push_back(x.second);
		cout<<x.second<<endl;
		if (count==k) 
            return v;
	}
        return v;
    }
};