class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int>ans;
        long long num = n-1;
        while(num || x)
        {
            if(x&1)
            {
               ans.push_back(1);
            }
            else{
                ans.push_back(num&1);
                num>>=1;
            }
            x>>=1;
        }
        num = 0;
        for(int i = ans.size()-1;i>=0;i--)
        {
           num<<=1;
           num|=ans[i];
        }
        return num;
    }
};