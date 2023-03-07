/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void swap(vector<int>& arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int minSwaps(vector<int> arr, int N)
    {
        int ans = 0;
        vector<int> temp = arr;
        map<int,int> h;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < N; i++) {
            h[arr[i]] = i;
        }
        for (int i = 0; i < N; i++) {
            if (arr[i] != temp[i]) {
                ans++;
                int init = arr[i];
                swap(arr, i, h[temp[i]]);
                h[init] = h[temp[i]];
                h[temp[i]] = i;
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(root==NULL) return 0;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> vv;
        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode* tt = q.front();
                v.push_back(tt->val);
                q.pop();
                if(tt->left) q.push(tt->left);
                if(tt->right) q.push(tt->right);
            }
            // vv.push_back(v);
            // for(int i=0; i<vv.size(); i++){
                int ted = minSwaps(v,v.size());
                count+=ted;
                // cout<<ted<<endl;
            // }
        }
        return count;
    }
};