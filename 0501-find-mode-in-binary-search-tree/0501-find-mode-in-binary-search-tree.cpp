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
    void inorder(TreeNode* root, map<int,int> &mp, int &maxx){
        if(root == NULL){
            return ;
        }
        inorder(root->left,mp,maxx);
        mp[root->val]++;
        maxx = max(maxx,mp[root->val]);
        inorder(root->right,mp,maxx);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp; int maxx = 0;
        inorder(root,mp,maxx);
        vector<int> ans;
        for(auto xx:mp){
            if(xx.second == maxx){
                ans.push_back(xx.first);
            }
        }
        return ans;
    }
};