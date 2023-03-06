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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> st;
        while(!q.empty()){
            int tem = q.size();
            vector<int> vv;
            for(int i=0; i<tem; i++){
                TreeNode* check = q.front();
                q.pop();
                if(check->left) q.push(check->left);
                if(check->right) q.push(check->right);
                vv.push_back(check->val);
            }
            st.push(vv);
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};