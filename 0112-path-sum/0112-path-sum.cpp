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
    bool flag = false;
    void check(TreeNode* root,int sum,int ts){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) {sum += root->val; if(sum == ts) flag = true;}
        sum += root->val;
        if(root->left != NULL) check(root->left,sum,ts);
        if(root->right != NULL) check(root->right,sum,ts);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        check(root,0,targetSum);
        return flag;
    }
};