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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) return {};
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            int temp = q.size();
            vector<int> vv;
            for(int i=0; i<temp; i++){
                TreeNode* tt = q.front();
                q.pop();
                if(tt->left) q.push(tt->left);
                if(tt->right) q.push(tt->right);
                vv.push_back(tt->val);
            }
            v.push_back(vv);
        }
        return v;
    }
};