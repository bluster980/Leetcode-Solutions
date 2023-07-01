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
    TreeNode* bst(vector<int>&pre,int l,int r){
        int in = l;
        if(in >= r) return NULL;
        TreeNode* temp = new TreeNode(pre[in]);
        while(in<pre.size() && pre[in] <= temp->val){
            in++;
        }
        temp->left = bst(pre,l+1,in);
        temp->right = bst(pre,in,r);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder,0,preorder.size());
    }
};