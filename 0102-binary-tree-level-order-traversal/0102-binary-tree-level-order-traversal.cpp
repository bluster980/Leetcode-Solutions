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
    vector<vector<int>> levelsOrder(TreeNode *root){
        vector<vector<int>> v;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode *cn = q.front(); q.pop();
            if(cn == NULL){
                if(q.empty()) break;
                else
                    {level++; q.push(NULL); v.push_back(temp); temp.clear();}
            }
            else{
                // cout<<cn->val<<" "<<level<<endl;
                temp.push_back(cn->val);
                if(cn->left) q.push(cn->left);
                if(cn->right) q.push(cn->right);
            }
            // level++;
        }
        v.push_back(temp);
        return v;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>>{};
        return levelsOrder(root);;
    }
};