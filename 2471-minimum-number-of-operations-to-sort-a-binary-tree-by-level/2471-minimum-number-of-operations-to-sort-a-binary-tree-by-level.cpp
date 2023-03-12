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
    int minSwap(vector<int> &v){
        int count = 0;
        vector<int> p = v;
        sort(p.begin(),p.end());
        unordered_map<int,int> mp;
        for(int i=0; i<p.size(); i++){
            mp[p[i]] = i;
        }
        int i=0;
        while(i < v.size()){
            while(i != mp[v[i]]){
                swap(v[mp[v[i]]],v[i]); count++;
            }
            i++;
        }
        return count;
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
            count += minSwap(v);
        }
        return count;
    }
};