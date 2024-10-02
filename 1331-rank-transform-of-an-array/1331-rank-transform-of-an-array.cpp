class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++) temp[i]=i;
        sort(temp.begin(),temp.end(),[&](int i,int j){return arr[i]<arr[j];});
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
               if (arr[temp[i]]==arr[temp[i-1]])
               {
                ans[temp[i]]=ans[temp[i-1]];
               }
               else 
               ans[temp[i]]=ans[temp[i-1]]+1;
            }
            else
            ans[temp[i]]=i+1;
        }
        return ans;

    }
};