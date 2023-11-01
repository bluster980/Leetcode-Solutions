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
    void inorder(TreeNode* root, int &cnt, int &maxx, int &prev, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        inorder(root->left,cnt,maxx,prev,ans);
        if(root->val == prev){
            cnt++;
        }
        else{
            if(cnt > maxx){
                maxx = cnt;
                ans.clear();
                ans.push_back(prev);
            }
            else if(cnt == maxx){
                ans.push_back(prev);
            }
            prev = root->val;
            cnt = 1;
        }
        inorder(root->right,cnt,maxx,prev,ans);
    }
    vector<int> findMode(TreeNode* root) {
        int cnt = 0, maxx = 1, prev = root->val;
        vector<int> ans;
        inorder(root,cnt,maxx,prev,ans); 
        if (cnt > maxx) {
            ans.clear();
            ans.push_back(prev);
        } else if (cnt == maxx) {
            ans.push_back(prev);
        }
        return ans;
    }
};