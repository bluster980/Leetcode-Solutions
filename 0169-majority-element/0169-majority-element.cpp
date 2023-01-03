class Solution {
public:
    int majorityElement(vector<int>& v) {
        int curr=v[0],count=1;
        for (int i = 1; i < v.size(); ++i)
        {
            if(v[i]!=curr) count--;
            else count++;
            if(count==0) {curr=v[i]; count=1;}
        }
        return curr;
    }
};