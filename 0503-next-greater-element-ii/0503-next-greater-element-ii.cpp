class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; vector<int> ans; unordered_map<int,int> mp;
        for(int i=0; i<nums.size()*2; i++){
            while(!st.empty() && (nums[i%nums.size()] > nums[st.top()])){
                mp[st.top()] = nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
            // cout<<i%nums.size()<<" ";
        }
        // cout<<endl;
        for(int i=0; i<nums.size(); i++)
            ans.push_back((mp.find(i)==mp.end())?-1:mp[i]);
        return ans;
    }
};