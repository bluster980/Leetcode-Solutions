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
 long long ans;
    vector<long long> left;
    
   void  dfs(TreeNode* root,int lvl,long long pos){
       if(!root) return;
        if(left.size()==lvl){ 
            left.push_back(pos);
        }
       
       ans=max(ans,pos-left[lvl]+1);
       dfs(root->left,lvl+1,pos*2-left[lvl]);
       dfs(root->right,lvl+1,pos*2+1-left[lvl]);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        ans=0;
        dfs(root,0,1);
        return ans;
    }
};