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
    // vector<int> v;
    void helper(TreeNode* root, int &k, int &temp) {
        if (!k || root==NULL) {
            return ;
        }
        helper(root->left, k,temp);
        if(k){            
            temp = root->val; k--;
        }
        helper(root->right, k,temp);
    }
    int kthSmallest(TreeNode* root, int &k) {
        int temp = 0; helper(root,k,temp);
        return temp;
        
    }
};