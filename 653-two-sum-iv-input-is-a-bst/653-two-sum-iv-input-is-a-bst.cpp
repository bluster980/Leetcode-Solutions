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
    map<int,int> mp;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        mp[root->val]++;
        // cout<<root->val<<" ";
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(auto x:mp){
            // cout<<k-x.first<<" ";
            if(mp.find(k-(x.first)) != mp.end() && (x.first != k-x.first)){
                return true;
            }
        }
        return false;
    }
};