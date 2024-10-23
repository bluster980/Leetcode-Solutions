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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
      root->val=0;
      if(root->left==NULL && root->right==NULL)
      return root;
      
      queue< TreeNode* >q,q1;
      if(root->left!=NULL )
      {
         root->left->val=0;
         q.push(root->left);
      }
      if(root->right!=NULL)
      {
         root->right->val=0;
         q.push(root->right);
      }
      
      vector<int> v;
      while(!q.empty())
      {
         int s=q.size();
         int sum=0;
         for(int i=0;i<s;i++)
         {
             int m=0;
             if(q.front()->left!=NULL)
             { 
                 q.push(q.front()->left);
                 m=m+q.front()->left->val;
             }
             if(q.front()->right!=NULL)
             {
                 q.push(q.front()->right);
                 m=m+q.front()->right->val;
             }
             sum=sum+m;
             q1.push(q.front());
             q.pop();
             v.push_back(m);
           }
        
         for(int i=0;i<v.size();i++)
          {
              if(q1.front()->left!=NULL)
              q1.front()->left->val=sum-v[i];
            
               if(q1.front()->right!=NULL)
               q1.front()->right->val=sum-v[i];
           
               q1.pop();
          }
         v.clear();
        }
     return root;
    }
};