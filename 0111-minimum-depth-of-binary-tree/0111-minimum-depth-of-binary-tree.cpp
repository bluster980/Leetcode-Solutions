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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q; q.push({root,1});
        while(!q.empty()){
            TreeNode* tmp = q.front().first; int x = q.front().second; q.pop();
            if(tmp->left==NULL && tmp->right==NULL) return x;
            if(tmp->left) q.push({tmp->left,x+1});
            if(tmp->right) q.push({tmp->right,x+1});
        }
        return -1;
    }
};